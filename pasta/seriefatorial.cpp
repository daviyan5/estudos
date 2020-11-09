#include <stdio.h>
#include <math.h>



int main(){
    int n,p;
    short x;
    scanf("%d",&n);
    double r=0,c;
    x=pow(-1,n+1);
    p=pow(2,n);
    for (int i = n; i > 0; i--){
        x=x*(-1);
        c=(double)1/(p-1);
        r=r*(i+1)+x*c;
        p=(p)/2;
    }
    printf("%.2lf",r*-1);
}