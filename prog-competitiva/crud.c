#include <stdio.h>
#include <string.h>
int main (){
    char data[100][16];
    int idp[10002],a=0;
    for (int i = 0; i < 10002; i++){
        idp[i]=-1;
    }
    printf("chegou\n");
    while(1){
        char comando[20];
        scanf("%s",comando);
        if(strcmp(comando,"POST")==0){
            char dado[16];
            int id;
            scanf("%d %s",&id,dado);
            if(a<100){
                strcpy(data[a],dado);
                idp[id]=a;
                printf("Adicionado: %d %s\n",id,dado);
                a++;
            }
            else printf("Banco cheio!");
        }
        if(strcmp(comando,"PUT")==0){
            char dado[16];
            int id;
            scanf("%d %s",&id,dado);
            if(idp[id]!=-1){
                strcpy(data[a],dado);
                printf("Atualizado: %d %s\n",id,dado);
            }
            else{
                printf("ID não encontrado!\n");
            }
        }
        if(strcmp(comando,"DELETE")==0){
            int id;
            scanf("%d",&id);
            if(idp[id]!=-1){
                printf("Excluido: %d %s\n",id,data[id]);
                idp[id]=-1;
                a--;
            }
            else{
                printf("ID não encontrado!\n");
            }
            
        }
        if(strcmp(comando,"GET")==0){
            int id;
            scanf("%d",&id);
            if(idp[id]!=-1){
                printf("Enviado: %d %s\n",id,data[id]);
            }
            else{
                printf("ID não encontrado!\n");
            }
        }
        if(strcmp(comando,"CLOSE")==0){
            printf("Dados no banco:\n");
            for (int p = 0; p < 10002; p++){
                if(idp[p]!=-1) printf("%d %s\n",p,data[idp[p]]);
            }
            return 0;
        }
    }
}

