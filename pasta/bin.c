#include <stdio.h>

int main()
{
    int x;
    scanf("%d",&x);
    for (x=x; x>1;x=x)
    {
        x=x/2;
        printf("%d",x%2);
        
    }
    
    




    return 0;
}