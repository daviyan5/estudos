#include <stdio.h>
#include <math.h>

int main()
{double casos,p,m,g,pj,mj,gj;
scanf("%lf %lf %lf %lf",&casos,&p,&m,&g);
p=p*25;
pj=p;
m=m*40;
mj=m;
g=g*70;
gj=g;
if ((casos==2)||(casos==3)||(casos==5)||(casos==7)||(casos==11)||(casos==13)||(casos==17)||(casos==19)||(casos==23)||(casos==29)||(casos==31)||(casos==37)||(casos==41)||(casos==43)||(casos==47)||(casos==53)||(casos==59)||(casos==61)||(casos==67)||(casos==71)||(casos==73)||(casos==79)||(casos==83)||(casos==87)||(casos==97)){
    while (casos>0){
    p=p*(1.125);
    m=m*(1.29);
    g=g*(1.22);
    casos=casos-1;
    }
    printf("%.2lf\n%.2lf",(p-pj)+(m-mj)+(g-gj),p+m+g);
}
else printf("0.00\n%.2lf",pj+mj+gj);
return 0;
}