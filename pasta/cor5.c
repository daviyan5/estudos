#include <math.h>
#include <stdio.h>

int main()
{
    int R1,R2,num,div;
    scanf("%d %d",&R1,&R2);
    for(R1;R1<=R2;R1++){
        div=0;
        for(num=1;num<=R1;num++){
            if (R1%num==0) div++;
        }
        if (div==2) printf("%d\n",R1);
    }
   
    return 0;
}