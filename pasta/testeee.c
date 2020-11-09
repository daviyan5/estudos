#include <stdio.h>

int main(){
    int x,i,p,c=0;
    scanf("%d",&x);
    p=3*x-1;
    x=x*x*-1;
    for(i=1;c<p;c++)
    {
        printf("%d ",x);
        x=x+i;
        i=i+2;
    }




    return 0;
}
