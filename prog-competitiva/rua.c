#include <stdio.h>
#include <string.h>
typedef struct {
    char nome[40];
    int idade;
    char sexo;
} Pessoa;

typedef struct {
    Pessoa pessoa[4];
} Familia;

typedef struct {
    int numApt;
    Familia familia;
} Apto;

typedef struct {
    Apto aptos[2];
} Andar;

typedef struct {
    int numero;
    Andar andares[20];
} Edficio;

typedef struct {
    int numero;
    Familia familia;
} Casa;

typedef struct {
    char nome[40];
    Casa casas[20];
    Edficio edfs[5];
} Rua;

typedef struct {
    Rua rua;
} Cidade;

int main() {
    int codig;
    Cidade ville;
    printf("Digite o nome da Rua: ");
    scanf("%s",ville.rua.nome);
    do{
        printf("1.Inserir Morador\n");
        printf("2.Encontrar Morador\n");
        printf("3.Sair do Sistema\n");
        printf("Digite o código da operação: ");
        scanf("%d",&codig);
        if(codig>3 || codig<0) printf("Inválido!\n");
        if(codig==1){
            int n,a,p,c,cas;
            printf("Casa (1) ou Apartamento (0) ? : ");
            scanf("%d",&cas);
            if(cas==1){
                printf("Digite o numero da Casa (0 até 19): ");
                scanf("%d",&n); //casa
                ville.rua.casas[n].numero=n;
                printf("Digite o numero da Pessoa (0 até 3): ");
                scanf("%d",&a); //pessoa
                printf("Digite o nome da Pessoa: ");
                scanf("%s",ville.rua.casas[n].familia.pessoa[a].nome);
                printf("Digite a idade da Pessoa: ");
                scanf("%d",&ville.rua.casas[n].familia.pessoa[a].idade);
                printf("Digite o sexo da Pessoa (M ou F): ");
                scanf("%s",&ville.rua.casas[n].familia.pessoa[a].sexo); //usei %s pra garantir que o scanf não registre um '' ou um /n
            }
            else{
                printf("Digite o numero do Edifício (0 até 4): ");
                scanf("%d",&n); //edificio
                printf("Digite o andar do Edifício (0 até 19): ");
                scanf("%d",&p); //andar
                printf("Digite o apartamento (0 até 1): ");
                scanf("%d",&c); //apartamento
                ville.rua.edfs[n].andares[p].aptos[c].numApt=c;
                printf("Digite o numero da Pessoa (0 até 3): ");
                scanf("%d",&a);
                printf("Digite o nome da Pessoa: ");
                scanf("%s",&ville.rua.edfs[n].andares[p].aptos[c].familia.pessoa[a].nome);
                printf("Digite a idade da Pessoa: ");
                scanf("%d",&ville.rua.edfs[n].andares[p].aptos[c].familia.pessoa[a].idade);
                printf("Digite o sexo da Pessoa (M ou F): ");
                scanf("%s",&ville.rua.edfs[n].andares[p].aptos[c].familia.pessoa[a].sexo);
            }
        }
        if(codig==2){
            int n,a,p,c,cas;
            char nomet[20];
            printf("Casa (1) ou Apartamento (0) ? : ");
            scanf("%d",&cas);
            if(cas==1){
                printf("Digite o numero da Casa (0 até 19): ");
                scanf("%d",&n);
                printf("Digite o nome da Pessoa: ");
                scanf("%s",nomet);
                for (int i = 0; i < 4; i++){ //laço de busca entre as pessoas da familia da casa
                    if(strcmp(ville.rua.casas[n].familia.pessoa[i].nome,nomet)==0){
                        printf("\nNome : %s\n",ville.rua.casas[n].familia.pessoa[i].nome);
                        printf("Idade : %d anos\n",ville.rua.casas[n].familia.pessoa[i].idade);
                        printf("Sexo : %c\n",ville.rua.casas[n].familia.pessoa[i].sexo);
                        printf("Numero da Casa : %d\n",n);
                        printf("Nome da Rua : %s\n\n",ville.rua.nome);
                        i=4;
                    }
                    else if(i==3) printf("Morador não encontrado!\n");
                }
                                
            }
            else{
                printf("Digite o numero do Edifício (0 até 4): ");
                scanf("%d",&n);
                printf("Digite o nome da Pessoa: ");
                scanf("%s",nomet);
                for (int i = 0; i < 20; i++){ //laço de busca, buscando em todos os andares, apartamentos e familias do edificio
                    for (int j = 0; j < 2; j++){
                        for (int k = 0; k < 4; k++){
                            if(strcmp(ville.rua.edfs[n].andares[i].aptos[j].familia.pessoa[k].nome,nomet)==0){
                                printf("\nNome : %s\n",ville.rua.edfs[n].andares[i].aptos[j].familia.pessoa[k].nome);
                                printf("Idade : %d anos\n",ville.rua.edfs[n].andares[i].aptos[j].familia.pessoa[k].idade);
                                printf("Sexo : %c\n",ville.rua.edfs[n].andares[i].aptos[j].familia.pessoa[k].sexo);
                                printf("Andar : %d\n",i);
                                printf("Apartamento : %d\n",j);
                                printf("Numero do Edificio : %d\n",n);
                                printf("Nome da Rua : %s\n\n",ville.rua.nome);
                                i=20;
                                k=4;
                                j=2;
                            }
                            else if(i==19 && j==1 && k==3) printf("Morador não encontrado!\n");
                        }
                    } 
                }
            }
        }
    }while(codig!=3);
    return 0;
    // o codigo não ficou tão específico pois alguns bugs podem ocorrer dependendo da entrada do usuario
    // mas registrou certo as estruturas nos meus testes
}
