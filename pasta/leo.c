#include <math.h>
#include <stdio.h>

int main(){
    int x,y;
    scanf("(%d,%d)",&x,&y);
    int a,n,b,m;
    scanf("%d*x^%d - %d*y^%d",&a,&n,&b,&m);
    int de=a*pow(x,n)-b*pow(y,m);
    if(de!=0){
        printf("a função está definida em (%d,%d)",x,y);        
    }
    else{
        printf("a função não está definida em (%d,%d) .-.",x,y);        
    }
    
}