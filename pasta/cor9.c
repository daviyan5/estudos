#include <stdio.h>
#include <math.h>

int main()
{float v1,v2,v3,energia,arma;
scanf("%f %f %f %f %c",&v1,&v2,&v3,&energia,&arma);
v1=v1+v2+v3;
if (arma=86){
    if (v1>0.8*energia){
        if ((v1-(68/30)*energia)<0) printf("Eba! Pedro sobreviveu");
        else printf("Que pena... Era um jovem tao promissor");
    }
    else if ((v1-(40/15)*energia)<0) printf("Eba! Pedro sobreviveu");
         else printf("Que pena... Era um jovem tao promissor");

}
else if (arma=67){
    if (v1>0.75*energia){
        if (v1-(85/40)*energia<0) printf("Eba! Pedro sobreviveu");
        else printf("Que pena... Era um jovem tao promissor");
    }
    else if (v1-(50/20)*energia<0) printf("Eba! Pedro sobreviveu");
         else printf("Que pena... Era um jovem tao promissor");


}
return 0;
}