#include <stdio.h>

int main(){
    FILE *arquivo;
    arquivo = fopen("C:\\Users\\gimhi\\OneDrive\\Documentos\\arquivo.txt", "ab");
    if(arquivo!=NULL){
        printf("Foi!\n");
        for(int i=0;i<10;i++){
            fprintf(arquivo,"Passou");
        }
        fclose(arquivo);
    }
    else printf("Não foi!\n");
    return 0;
}