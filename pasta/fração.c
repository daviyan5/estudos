#include <stdio.h>

int main()
{
    float real,aux;
    int num,den=10000,i;
    scanf("%f",&real);
    aux=real;
    for(i=0;num!=aux;i++)
    {
        aux=10*aux;
        num=aux;
    }
    den=pow(10,i);
    num=real*den;
    for (i=0;num%5==0 && den%5==0; i++)
    {
        num=num/5;
        den=den/5;
        printf("%d %d\n",num,den);
    }
    for (i=0;num%2==0 && den%2==0; i++)
    {
        num=num/2;
        den=den/2;
        printf("%d %d\n",num,den);
    }
    printf("%d/%d",num,den);
    

    return 0;
}