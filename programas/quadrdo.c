#include <stdio.h>
int main (){
   int n,maior=0,foi=0;
   scanf("%d",&n);
   int matriz[n][n];
   for (int i = 0; i < n; i++){
       for (int j = 0; j < n; j++){
           scanf("%d",&matriz[i][j]);
       }
   }
   for (int i = 0; i < n; i++){
       for (int j = 0; j < n; j++){
           if(matriz[i][j]==1){
               int a=1;
               foi=0;
               for (a = 1; a <= n && foi==0; a++){
                   for (int k = 0; k < a && foi==0; k++){
                       for (int l = 0; l < a && foi==0; l++){
                           printf("matriz[%d][%d]=%d a=%d",i+k,j+l,matriz[i+k][j+l],a);
                           if(matriz[i+k][j+l]!=1 || (j+l)>=n) foi=1;
                           printf(" foi=%d\n",foi);
                       }
                       if((i+k)>=n) foi=1;
                   }
                   if(a>maior && foi==0) maior=a;
               }
           }
       }
   }
   printf("%d",maior*maior);
   return 0;
}

