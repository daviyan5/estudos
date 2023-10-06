#include <stdio.h>
#include <stdlib.h>

int main(){
   int n;
   scanf("%d",&n);
   for (int i = 0; i < n; i++){
       long long int v;
       scanf("%lld",&v);
       printf("%lld\n",(v*(v*v+1))/2);
   }
   
   return 0;
}