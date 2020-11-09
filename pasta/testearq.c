#include <stdio.h>
typedef struct{
    int a;
    char nome[100];
} nomes;
int main(){
    nomes a,b;
    a.a=1;
    b.a=2;
    scanf("%s %s",a.nome,b.nome);
    a=b;
    printf("a-> n=%d s=%s\nb-> n=%d s=%s\n",a.a,a.nome,b.a,b.nome);
    
}