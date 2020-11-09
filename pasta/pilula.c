#include <stdio.h>
#include <math.h>
int main(){   
    int h1,m1,h2,m2,h3,m3;
    scanf("%d %d %d %d %d %d",&h1,&m1,&h2,&m2,&h3,&m3);
    if (h1>12) printf ("f\n");
    else printf ("v\n");
    if (h2>=24 || h2<0 || h2*60+m2!=h1*60+m1+192 ) printf("f\n");
    else printf("v\n");
    if (h3>=24 || h3<0 || h3*60+m3!=(h2*60)+m2-60) printf("f\n");
    else printf("v\n");
    if (h1>12 || h2>=24 || h2<0 || h2*60+m2!=h1*60+m1+192 || h3>=24 || h3<0 || h3*60+m3!=(h2*60)+m2-60) printf("falha");
    else printf("sucesso");
    return 0;
}