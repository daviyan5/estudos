#include <stdio.h>
#include <string.h>
int main (){
   int m1[3][3],m2[3][3],m3[3][3];
   for (int i = 0; i < 3; i++){
       for (int j = 0; j < 3; j++){
           scanf("%d",&m1[i][j]);
       }
   }
   for (int i = 0; i < 3; i++){
       for (int j = 0; j < 3; j++){
           scanf("%d",&m2[i][j]);
           m3[i][j]=0;
       }
   }
   for (int i = 0; i < 3; i++){
       for (int j = 0; j < 3; j++){
           for (int k = 0; k < 3; k++){
               m3[i][j]+=(m1[i][k]*m2[k][j]);
           }
           
       }
   }
   for (int i = 0; i < 3; i++){
       for (int j = 0; j < 3; j++){
           printf("%d ",&m3[i][j]);
       }
       printf("\n");
   }
   return 0;
}

