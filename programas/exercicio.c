#include <stdio.h>

int main(){
    int n,s=0;
    while(n>0){
        printf("Digite um numero natural: ");
        scanf("%d",&n);
        s=n+s;
    }
    if(n<0) s=s-n;
    printf("Soma dos numeros digitados: %d\n",s);
}