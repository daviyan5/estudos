#include <stdio.h>

int main(){
    int op=0;
    float b[2]={0,0};
    while (op>-1){
        scanf("%d",&op);
        if(op==-1) break;
        float v;
        scanf("%f",&v);
        printf("foi op=%d\n",op);
        b[op]+=v;
    }
    printf("Creditos: R$ %.02f\n",b[1]);
    printf("Debitos: R$ %.02f\n",b[0]);
    printf("Saldo: R$ %.02f\n",b[1]-b[0]);
}