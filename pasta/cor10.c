#include <math.h>
#include <stdio.h>

int main()
{
    int num,x=-4,y=-1;
    while(num!=-1)
    {
        scanf("%d",&num);
        if (num!=-1)
        {
            x=-4;
            while(num!=-2 && x<=24 )
            {
                while(y<=24 && num!=-2)
                {
                    if (x*y*(19-(x+y))==num) 
                    {
                        num=-2;
                        printf("INFECTADO\n");
                    }
                    else y++;
                }
                y=-1;
                x++;

                
            }
            if (x>24) printf("SAFE\n");
        }
    }
    
    
    return 0;
}