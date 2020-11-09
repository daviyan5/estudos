#include <stdio.h>
#include <math.h>

int main()
{int n,x,i=0;
scanf("%d %d",&n,&x);
if ((n%2==0 && x%2==0)||(n%2==1 && x%2==0)){
    printf("%d",x+1);
}
else printf("%d",x-1);
if ((n%2==0 && x%2==0)||(n%2==0 && x%2==1)){
    printf(" 0 0 ");
    while (i<n-3){
        printf("1 ");
        i++;
    }
}
else {
    printf(" 0 ");
    while (i<n-2){
        printf("1 ");
        i++;
    }
}

    

return 0;
}