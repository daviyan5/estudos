#include <stdio.h>

typedef struct{
    int id_encomenda;
    char endereco[100];
    char destinatario[100];
} encomenda;

encomenda *obterEncomendas(int *qtEncomendas){
    encomenda *Eaux=NULL; //Criando um ponteiro do tipo encomenda para ser retornado no final
    FILE *bin;
    bin = fopen("/encomendas.bin","r+"); //Abrindo o arquivo
    if(bin==NULL){   //Verificando se há algo no arquivo
        printf("Falha na abertura!\n");
        exit(1);
    }
    Eaux = (encomenda*) realloc(Eaux,sizeof(encomenda)); //Alocando o primeiro espaço
    if(Eaux==NULL){ //Verificação de memoria
        printf("Falha na memória!\n");
        exit(1);
    }
    while(fread(&Eaux[*qtEncomendas],sizeof(encomenda),1,bin)==1){ //Aqui uso o fread para alocar 1 "bloco" de tamanho sizeof(encomenda) para a posição "*qtEncomendas" do ponteiro de encomendas. Caso algo diferente de 1 seja retornado, significa que o bloco esta incompleto ou é fim do arquivo, encerrando o loop.
        printf("ID = %d\nEnderec = %s\nDestino = %s\n",Eaux[*qtEncomendas].id_encomenda,Eaux[*qtEncomendas].endereco,Eaux[*qtEncomendas].destinatario); //Apenas para verificação. Pode ser retirado sem problemas.
        *qtEncomendas=*qtEncomendas+1; // Aqui sinalizo que há +1 encomenda no total, ja que este ponteiro começa em 1
        Eaux = (encomenda*) realloc(Eaux,sizeof(encomenda)*(*qtEncomendas+1)); //Aloco o espaço necessário
    }
    if(*qtEncomendas==0){ //Caso não haja nada no arquivo ou a leitura do bloco saia errrada. Por segurança
        free(Eaux);
        fclose(bin);
        return NULL;
    }
    fclose(bin); //Fecho o arquivo
    return Eaux; //Retorno o ponteiro usado
}
void entregarEncomenda(int id_encomenda, encomenda *encomendas, int *qtEncomendas){
    int ach=-1; //Sinaliza se foi achado ou não o id recebido
    if(encomendas==NULL){ //Caso não haja mais nada no ponteiro
        printf("Não há nenhuma encomenda!\n");
        return 0;
    }
    for (int i = 0; i < *qtEncomendas; i++){ //Procura o id no ponteiro
        if(encomendas[i].id_encomenda==id_encomenda){
            ach=i; //Caso ache, a variavel se torna o indice 
            i=*qtEncomendas; //Apenas para sair do loop
        }
    }
    if(ach==-1){ //Não achou no loop
        printf("ID inválido!\n");
        return 0;
    }
    printf("ID encontrado!\nEndereço: %s\nDestinatario: %s\n",encomendas[ach].endereco,encomendas[ach].destinatario); //Apenas para verificação, pode ser removido
    for (int i = ach; i < *qtEncomendas-1; i++){
        encomendas[i]=encomendas[i+1]; //Aqui substituo a encomenda encontrada pela seguinte, ja que são ambas estruturas do mesmo tipo. Dessa forma a ordem é preservada e a encomenda entregue é apagada
    }
    *qtEncomendas=*qtEncomendas-1;
    encomendas = (encomenda*) realloc(encomendas,sizeof(encomenda)*(*qtEncomendas)); //Realoca para um novo tamanho
    printf("Encomenda entregue!\n");
}

void finalizarEntregas(encomenda *encomendas, int qtEncomendas){
    FILE *bin;
    bin = fopen("/encomendas.bin","w+"); //Abro o arquivo como escrita, ja "passando por cima" do que tinha antes
    if(bin==NULL){
        printf("Falha na abertura!\n");
        exit(1);
    }
    fwrite(encomendas,sizeof(encomenda),qtEncomendas,bin); //Reescrevo no arquivo o ponteiro com as encomendas que não foram entregues
    printf("Entregas reescritas com sucesso!\n");
    fclose(bin);
}

int main(){
    int *qtEnc; // Ponteiro do total de encomendas
    qtEnc = (int*) malloc(sizeof(int)); //Aloco apenas 4 bytes
    if(qtEnc==NULL){ // Verificação de memória
        printf("Falha na memória!\n");
        exit(1);
    }
    *qtEnc=0; //Começa com 0 para inicializar o ponteiro
    encomenda *Enc = obterEncomendas(qtEnc);
    if(Enc==NULL){ // Caso a função retorne nulo ou haja falha de memória
        printf("Não há encomenda!\n");
        exit(1);
    }
    int op; //Variavel usada para registrar as opçoes
    do{ //Loop do menu
        printf("\n1........Entregar encomenda.\n2........Encerrar programa.\n");
        printf("Digite sua opção: ");
        scanf("%d",&op); 
        if(op>2 || op<1) printf("Opção Inválida!\n"); 
        else if(op==1){
            int id;
            printf("Digite o id da entrega: ");
            scanf("%d",&id);
            entregarEncomenda(id,Enc,qtEnc);
        }
    }   while(op!=2);
    finalizarEntregas(Enc,*qtEnc);
    free(qtEnc); //Libero os ponteiros usados
    free(Enc);
    return 0;
}

