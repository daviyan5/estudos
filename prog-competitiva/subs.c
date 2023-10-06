#include <stdio.h>
#include <string.h>
int main (){
   char s1[400],s2[400];
   scanf("%s\n%s",s1,s2);
   int len=strlen(s1),len2=strlen(s2),total=0;
   for (int i = 0; i < len; i++){
       if(s1[i]==s2[0]){
           int cont=0;
           for (int j = i; j < i+len2 && j<len; j++){
               if(s1[j]==s2[j-i]) cont++;
               else break;             
           }
           if (cont==len2) total++;
       }
   }
   printf("%d\n",total);
   
}

