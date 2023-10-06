#include <stdio.h>
#include <string.h>
int main (){
    char nome[10000],nomef[10000];
    int n,prod,prodf=-1;
    printf("Digite o numero de pessoas: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%s",&nome);
        scanf("%d",&prod);
        if(prod > prodf){
            prodf=prod;
            stpcpy(nomef,nome);        
        }
    }
    printf("%s é a pessoa mais produtiva!\n",nomef);
    return 0;
}

