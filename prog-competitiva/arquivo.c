#include <stdio.h>

int main(){
    FILE *arquivo;
    arquivo = fopen("/home/davi/Documentos/arquivo.txt","w+");
    if(arquivo!=NULL){
        fprintf(arquivo,"Funfou");
        fclose(arquivo);
    }
    else printf("Não Foi!");
    return 0;
}