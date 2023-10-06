#include <stdio.h>
#include <math.h>

int main(){
    int a,b,idf;
    double probf=1,aux=0;
    scanf("%d %d",&a,&b);
    for(;;){
        aux=0;
        int id,d;
        double c;
        scanf("%d %lf %d",&id,&c,&d);
        if(id==-1) break;
        int r=(d/b)+1;
        for (int i = r; a >= i; i++){
            long long int num=1,den=1;
            if(a>2*i){
                for (int j = a-i+1; j <= a ; j++){
                    num=num*j;
                }
                for (int j = 1; j <= i ; j++){
                    den=den*j;
                }

            }
            else{
                for (int j = i+1; j <= a ; j++){
                    num=num*j;
                }
                for (int j = 1; j <= a-i ; j++){
                    den=den*j;
                }
            }
            double p1=1,p2=1;
            for(int j=0;j<i;j++){
                p1=p1*c;

            }
            for(int j=0;j<a-i;j++){
                p2=p2*(1-c);
            }
            aux=aux+p1*p2*num/den;
        }
        if(aux<probf){
            idf=id;
            probf=aux;
        }
    }
    printf("O roteador escolhido foi o %d, com probabilidade de %.5lf",idf,probf);
    return 0;
}