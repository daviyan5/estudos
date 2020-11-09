#include <stdio.h>
#include <math.h>

int myFunction(int x,int y){
    if (x>y) return x;
    else return y;
}
int main(void){
    int a,b,c;
    scanf("%d %d",&b,&c);
    a=myFunction(c,b);
    printf("%d\n",a);
    return 0;
}