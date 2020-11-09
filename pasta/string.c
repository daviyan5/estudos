#include <stdio.h>
#include <string.h>
int main (){
    char nome[10000],nomef[10000];
    int n,prod,prodf=-1;
    printf("Digite o numero de pessoas: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        printf("\nDigite o nome: ");
        scanf("%s",&nome);
        printf("\nDigite a produtividade: ");
        scanf("%d",&prod);
        if(prod > prodf){
            prodf=prod;
            strcpy(nome,nomef);
        }
    }
    printf("\n%s é a pessoa mais produtiva!",prodf);
    return 0;
}