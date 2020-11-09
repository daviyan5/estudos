#include <stdio.h>
#include <math.h>

int main()
{
    long int i=0,n[1000],k,l,a;
	scanf("%d",&l);
    aqui:for(i=1;i<1000 && l!=-1;i++)
	{
        scanf("%ld",&l);
		n[(i+1)]=l;
		l=n[(i+1)];
		printf("i=%ld l=%ld  ",i,l);
	}
    if (l==-1 && i==0) return 0;
	else
	{
		scanf("%ld",&k);
		for(i=0,a=0;i<1000;i++)
		{
			if (n[i+1]==k) a++;
		}
		scanf("%d",&l);
		printf("%ld appeared %ld times",k,a);
	}
	if(l!=-1)
	{
	    n[1]=l;
	    goto aqui;
	}
	else return 0;
}