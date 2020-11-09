#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
   int n=10000,impar=0;
   int casa[n+1],ini=0;
   for (int i = 0; i < n; i++){
       casa[i]=0;
   }
   char aux[10000],esp;
   for (int i = 0; i < n; i++){
       fgets(aux,20002,stdin);
   }
   
   for (int i = 0; i < n; i++){
       if(casa[i]!=0){
           if (casa[i]%2!=0) impar=i;
           for(int j=casa[i];j>0;j--){
               printf("%d ",i);
           }
       }
   }
   printf("\n%d\n",impar);
}