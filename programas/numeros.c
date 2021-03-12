#include <stdio.h>
#include <string.h>
int main (){
   int c=0;
   for (int i = 1; i < 6; i++){
       for (int j = 1; j < 6; j++){
           printf("comb[%d]= 1 3 %d %d\n",c,i,j);
           c++;
       }
   }
   printf("\n");
   for (int i = 1; i < 6; i++){
       for (int j = 1; j < 6; j++){
           printf("comb[%d]= %d 1 3 %d\n",c,i,j);
           c++;
       }
   }
   printf("\n");
   for (int i = 1; i < 6; i++){
       for (int j = 1; j < 6; j++){
           printf("comb[%d]= %d %d 1 3\n",c,i,j);
           c++;
       }
   }
   printf("\n");
   c=0;
   for (int i = 1; i < 6; i++){
       for (int j = 1; j < 6; j++){
           for (int h = 1; h < 6; h++){
               for (int k = 1; k < 6; k++){
                   printf("combt[%d]= %d %d %d %d\n",c,i,j,h,k);
                   c++;
               }
               
           }
           
       }
   }
}

