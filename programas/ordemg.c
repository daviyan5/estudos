#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    double n;
    int i=0;
    scanf("%lf",&n);
    while(n/10>=10){
        n=n/10;
        i++;
    }
    if(n>sqrt(10)){
        i++;
    }
    printf("%d\n",i);
}
