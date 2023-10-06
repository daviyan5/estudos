#include <stdio.h>


int main(){
    int p,l,a,h,m;
    scanf("%d %d %d",&a,&l,&p);
    scanf("%d",&m);
    printf("%d\n",a>l?a*m:(l>p?l*m:p*m));
}
