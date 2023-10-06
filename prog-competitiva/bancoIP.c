#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    char senha[10];
} Gerente;

typedef struct {
    char nome[30];
    char senha[10];
    int conta;
    float saldo;
} Cliente;

typedef struct {
    Gerente gerente;
    int qtdCli;
    Cliente *clientes;
} Banco;

void configuraBanco(Banco *bancoIP) {
    strcpy((bancoIP -> gerente).nome, "Paulo Guedes");
    strcpy((bancoIP -> gerente).senha, "bolsonaro");
    bancoIP -> qtdCli = 0;
    bancoIP -> clientes = NULL;
}

void menuBanco() {
    printf("Menu do Banco\n\n\n");
    printf("1.......Menu Gerente\n\n");
    printf("2.......Menu Cliente\n\n");
    printf("3.......Sair do banco\n\n\n");
    printf("Opcao: ");
}

void menuGerente() {
    printf("Menu do Gerente\n\n\n");
    printf("1.......Adicionar cliente\n\n");
    printf("2.......Remover cliente\n\n");
    printf("3.......Listar clientes\n\n");
    printf("4.......Encontrar cliente\n\n");
    printf("5.......Voltar ao menu do banco\n\n\n");
    printf("Opcao: ");
}

int senhaValida(char *senha) {
    char senhaTmp[10];
    printf("Digite sua senha: ");
    scanf(" %9s", senhaTmp);
    return !strcmp(senha, senhaTmp);
}
//fiz uma alteração na posição dessa função para que ela possa ser chamada na função de adicionar cliente, assim, evitando duplicatas no registro de um novo cliente
int encontrarCliente(Banco *bancoIP,int conta) { //tambem alterei os parâmetros, para que a conta procurada ja fosse incluida na função, para facilitar seu uso
    int iCli;                                   
    char naoEnc = 0;                             
    for(iCli=0; iCli < (bancoIP -> qtdCli) && !naoEnc; iCli++)
        if(bancoIP -> clientes[iCli].conta==conta) naoEnc=1;
    return (!naoEnc?-1:iCli);
}

void adicCliente(Banco *bancoIP) {
    Cliente *bTmp;
    bTmp = (Cliente *) realloc(bancoIP -> clientes, ((bancoIP -> qtdCli) + 1)*sizeof(Cliente));
    if(bTmp == NULL) { printf("Sem memoria. Banco OUT!\n"); free(bancoIP -> clientes); exit(1); }
    bancoIP -> clientes = bTmp;
    printf("Digite nome: ");
    scanf(" %29[^\n]", (bancoIP -> clientes)[bancoIP -> qtdCli].nome);
    printf("Digite senha: ");
    scanf(" %9[^\n]", (bancoIP -> clientes)[bancoIP -> qtdCli].senha);
    int foi=0,ctemp;
    do{ //um loop para que uma conta valida seja registrada
        printf("Digite conta: ");
        scanf("%d",&ctemp);
        if(encontrarCliente(bancoIP,ctemp)==-1) foi=1; //chamando a função de busca
        else printf("Conta inválida!\n");
    }while(!foi);
    (bancoIP -> clientes)[bancoIP -> qtdCli].conta=ctemp;
    printf("Digite saldo: ");
    scanf("%f", &((bancoIP -> clientes)[bancoIP -> qtdCli].saldo));
    (bancoIP -> qtdCli)++;
}

void listarClientes(Banco *bancoIP) {
    int iCli;
    for(iCli=0; iCli < (bancoIP -> qtdCli); iCli++) {
        printf("Cliente: %s\n", (bancoIP -> clientes)[iCli].nome);
        printf("Conta: %d\n", (bancoIP -> clientes)[iCli].conta);
        printf("Saldo: %.2f\n", (bancoIP -> clientes)[iCli].saldo);
    }
}

void removerCliente(Banco *bancoIP){
    int ctemp;
    printf("Digite a conta a ser removida:");
    scanf("%d",&ctemp);
    int enc=encontrarCliente(bancoIP,ctemp); //função de busca para remover o cliente
    if(enc!=-1){
        printf("Cliente encontrado:\n\n");
        printf("Nome: %s\n\n",(bancoIP->clientes)[enc-1].nome); //demonstra os dados salvos, para confirmação
        printf("Senha: %s\n\n",(bancoIP->clientes)[enc-1].senha);
        printf("Saldo: %.2f\n\n",(bancoIP->clientes)[enc-1].saldo);
        printf("Deseja prosseguir?\n\n");
        printf("1.......Sim\n\n");
        printf("2.......Nao\n\n");
        int res;
        scanf("%d",&res);
        if (res==1){
            for (int i = enc-1; i < bancoIP -> qtdCli - 1; i++){ //copiando os dados na fila, de maneira que cada um dos clientes registrado após o que queremos apagar tenha sua posição diminuída
                (bancoIP -> clientes)[i] = (bancoIP -> clientes)[i+1];
            }
            (bancoIP -> qtdCli)--; 
            bancoIP -> clientes = (Cliente *) realloc(bancoIP -> clientes,(bancoIP -> qtdCli)*sizeof(Cliente)); //efetivamente diminuindo a memoria registrada, realocando com um tamanho menor
            printf("Cliente removido!\n\n");
        }
    }
    else printf("Cliente nao encontrado!");
}

void sisGerente(Banco *bancoIP) {
    int opcao;
    if(senhaValida((bancoIP -> gerente).senha)) {
        do {
            menuGerente();
            scanf("%d", &opcao);
            switch(opcao) {
                case 1: adicCliente(bancoIP); break;
                case 2: removerCliente(bancoIP); break;
                case 3: listarClientes(bancoIP); break;
                case 4: 
                    printf("Digite a conta a ser pesquisada: "); //uma pequena alteração na busca de uma conta
                    int ctemp; 
                    scanf("%d",&ctemp);
                    if(encontrarCliente(bancoIP,ctemp)==-1) printf("Cliente nao encontrado!\n"); 
                    break;
                case 5: printf("Ate mais\n"); break;
                default: printf("Opcao invalida\n");
            }
        }while(opcao!=5);
    } else printf("Senha invalida\n");
}

int main() {
    Banco bancoIP;
    int opcao;
    configuraBanco(&bancoIP);
    do {
        menuBanco();
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: sisGerente(&bancoIP); break;
            case 2: printf("Cliente\n"); break;
            case 3: printf("Obrigado por usar o Banco IP\n"); break;
            default: printf("Opcao invalida\n");
        }
    }while(opcao!=3);
    return 0;
}