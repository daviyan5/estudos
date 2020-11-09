#include <stdio.h>
#include <math.h>

int main()
{
   int i,n[1001],k,l,c=0;
   while(1)
   {
       for(i=1;i<2 && l!=-1;i++)
       {
           scanf("%d",&l);
           n[i]=l;
       }
       if (l==-1) return 0;
       scanf("%d",&k);
       c=0;
       for(i=1;i<2;i++)
       {
           if (n[i]==k) c++;
       }
       printf("%f appeared times",pow(k,c));
   }
   return 0;
}