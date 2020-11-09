#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf("%d",&n);
    double eq1=0,eq2=0,eq3=0,aux=0;
    //eq 1//
    for (int i = 0; i < n; i++){
        if(i%2==0){
            aux=aux+(1/(double)(2*i+1));
        }
        else{
            aux=aux-(1/(double)(2*i+1));
        }
    }
    eq1=4*aux;
    aux=0;
    //eq2//
    for (int i = 0; i < n; i++){
        aux=aux+2/((double)(4*i+1)*(4*i+3));
    }
    eq2=4*aux;
    aux=0;
    //eq3//
    for (int i = 0; i < n-1; i++){
        if(i%2==0){
            aux=aux+(4/(double)((2*i+2)*(2*i+3)*(2*i+4)));
        }
        else{
            aux=aux-(4/(double)((2*i+4)*(2*i+3)*(2*i+2)));
        }
    }
    eq3=aux+3;
    printf("%lf - %lf\n%lf - %lf\n%lf - %lf\n",eq1,eq1/M_PI,eq2,eq2/M_PI,eq3,eq3/M_PI);
    return 0;
}