#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int a,i=0,n;
    scanf("%d",&n);
    while(i<=n)
    {
        scanf("%d",&a);
        if (a%2==0) printf("%d\n",a+1);
        else printf("%d\n",a);
        i++;
    }
	return 0;
}