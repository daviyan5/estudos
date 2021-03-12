#include <string.h>
#include <stdio.h>

int main(){
    float *reais=NULL;
    int total=0;
    float ent=0,media=0;
    do{
        scanf("%f",&ent);
        total++;
        reais=(float*) realloc(reais,total*sizeof(float)); //realoca o tamanho total necessario
        if(ent>0){
        reais[total-1]=ent;
        media+=ent;
        }
    } while (ent>=0 && reais!=NULL);
    media=media/total;
    float *maiores=NULL;
    int a=0;
    for (int i = 0; i < total && reais!=NULL; i++){
        if(reais[i]>=media){
            a++;
            maiores=(float*) realloc(maiores,a*sizeof(float)); //realoca o tamanho 'a' necessario
            maiores[a-1]=reais[i];
            printf("%f\n",maiores[a-1]); //printa os valores maiores
        }
    }
    free(reais);
    free(maiores);
    return 0;
}