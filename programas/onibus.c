#include <string.h>
#include <stdio.h>

typedef struct{
    int passagem;
    char data[10];
    char de[100];
    char para[100];
    int poltrona;
    int idade;
    char nome[150];
}ficha;


int main(){
    ficha oni[44];
    int i;
    float media=0;
    for (i = 0; i < 44; i++){
        int temp;
        scanf("%d",&temp);
        if(temp<0) break;
        oni[i].passagem=temp;
        scanf("%s\n",oni[i].data);
        printf("data=%s\n",oni[i].data);
        scanf("%[^\n]\n",oni[i].de);
        printf("de=%s\n",oni[i].de);
        scanf("%[^\n]",oni[i].para);
        printf("para=%s\n",oni[i].para);
        scanf("%d",&oni[i].poltrona);
        printf("polt=%d\n",oni[i].poltrona);
        scanf("%d\n",&oni[i].idade);
        printf("iadde=%d\n",oni[i].idade);
        scanf("%[^\n]",oni[i].nome);
        printf("nom=%s\n",oni[i].nome);
        
        media+=oni[i].idade;
    }
    media=media/i;
    for (int j = 0; j < i; j++){
        if(oni[j].poltrona%2==0 && oni[j].idade>media){
            printf("%s\n",oni[j].nome);
        }
    }
    return 0;
}