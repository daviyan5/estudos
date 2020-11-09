#include <stdio.h>

int main()
{
    int a,i;
    float p=0;
    scanf("%d",&a);
    for (i=1;pow(5,i)<=a; i++)
    {
        p=(1/(pow(5,i)))+p;
    }
    printf("%.0f",p*(float)a);
    return 0;
}