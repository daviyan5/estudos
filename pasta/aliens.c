#include <stdio.h>

int main()
{
    int i,a,n,t=0;
    float x;
    scanf("%d",&n);
    for(a=0;a<n;a++)
    {
        scanf("%f",&x);
        for(i=3;180*((float)i-2)/(float)i<=x && x<180;i++)
        {
            if (180*((float)i-2)/(float)i==x) t++;
        }
        i=3;
        if (t==0) printf("NAO\n");
        else printf("SIM\n");
        t=0;
    }

    return 0;
}