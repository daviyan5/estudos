#include <stdio.h>
#include <math.h>

int main()
{
    int i,t=0;
    long long int a1,a2,n;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld",&a1,&a2);
        t=0;
        while (a1>0 || a2>0)
        {
            if (a1%2!=a2%2) t++;
            a1=a1/2;
            a2=a2/2;
        }
        printf("%d\n",t);
    }
    return 0;
}