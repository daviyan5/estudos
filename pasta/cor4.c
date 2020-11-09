#include <stdio.h>

int main()
{
    int a,b,rest,ofa,ofb;
    float n,pA,pB,cA,cB;
    scanf("%f %d %f %d %f",&n,&a,&pA,&b,&pB);
    ofa=a;
    ofb=b;
    cA=(float)a/pA;
    cB=(float)b/pB;
    a=0;
    b=0;
    if (cA>cB)
    {
        while (n/pA>=1)
        {
            n=n-pA;
            a++;
        }
        while (n/pB>=1)
        {
            n=n-pB;
            b++;
        }
        
    }
    else if (cB>cA)
    {
        while (n/pB>=1)
        {
            n=n-pB;
            b++;
        }
        while (n/pA>=1)
        {
            n=n-pA;
            a++;
        }
        
    }
    else if (cA=cB)
    {
       if (pA>pB)
       {
           while (n/pA>=1)
           {
              n=n-pA;
              a++;
           }
           while (n/pB>=1)
            {
                n=n-pB;
                b++;
            }
           
        }
        else
        {
            while (n/pB>=1)
            {
                n=n-pB;
                b++;
            }
            while (n/pA>=1)
           {
              n=n-pA;
              a++;
           }
        }
         
    }
    rest=(a+b);
    
    while (rest>=5)
    {
        rest=rest-5;
        if (ofa>ofb) b++;
        else a++;
        
    }
    rest=10-((a+b)%10);
    if (rest==10 && a==2) rest=0;
    if (rest>=5)
    {
        rest=rest-1;
        if (ofa>ofb) b++;
        else a++;
    }
    if (pB>pA)
    {
        a=a+rest;
        if (ofa>ofb) printf("%d %d %d",b,a,rest);
        else printf("%d %d %d",a,b,rest);
    }
    else if(pB<pA)
    {
        b=b+rest;
        if (ofa>ofb) printf("%d %d %d",b,a,rest);
        else printf("%d %d %d",a,b,rest);
    }
    else if (a>b)
    {
        a=a+rest;
        if (ofa>ofb) printf("%d %d %d",b,a,rest);
        else printf("%d %d %d",a,b,rest);
    }
    else 
    {
        b=b+rest;
        if (ofa>ofb) printf("%d %d %d",b,a,rest);
        else printf("%d %d %d",a,b,rest);
    }
    return 0;
}