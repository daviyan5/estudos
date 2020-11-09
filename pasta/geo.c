#include <stdio.h>

int main()
{
    float x,y,i;
    for(i=0;x!=0 || y!=0;i++)
    {
        scanf("%f %f",&x,&y);
        if (x==0 && y==0) break;
        else if (x>0)
        {
            if ((3*x-(y)>=0) && ((x/3)-(y)<=0)) printf("INTERIOR\n");
            else printf("EXTERIOR\n");
        }
        else  
        {
            if ((3*x-(y)<=0) && ((x/3)-(y)>=0)) printf("INTERIOR\n");
            else printf("EXTERIOR\n");
        }
    }
    return 0;
}