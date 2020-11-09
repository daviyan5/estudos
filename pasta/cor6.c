#include <math.h>
#include <stdio.h>

int main()
{
    int P,N;
    float M,K;
    scanf("%d %d %f %f",&P,&N,&M,&K);
    printf("%.4f",1-pow(1-((1-pow((1-M*K),P))*K),N));
    return 0;
}