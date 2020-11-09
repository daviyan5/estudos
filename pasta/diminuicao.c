#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int idade;
    int chave;
    char nome[30];
} ind;
int main(){
    ind *indv=NULL;
    int n;
    printf("Digite a quantidade de contas\n");
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        indv = (ind*) realloc(indv,(i+1)*sizeof(ind));
        printf("Digite a chave da conta\n");
        scanf("%d",&indv[i].chave);
        printf("Digite a idade da conta\n");
        scanf("%d",&indv[i].idade);
        printf("Digite o nome da conta\n");
        scanf("%s",&indv[i].nome);
    }
    printf("Digite a chave a ser apagada\n");
    scanf("%d",&n);
    return 0;
    
}