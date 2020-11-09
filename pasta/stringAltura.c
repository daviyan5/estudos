#include <stdio.h>
#include <string.h>
int main (){
   int fim=0;
   float altura,alto=0,baixo=10;
   char nome[30],nomeb[30],nomea[30];
   while (fim==0){
       scanf("%s",&nome);
       scanf("%f",&altura);
       char s[4];
       scanf("%s",&s);
       if(!strcmp(s,"FIM")) fim=1;
       if(altura>alto){
           alto=altura;
           strcpy(nomea,nome);
        }
        if(altura<baixo){
            baixo=altura;
            strcpy(nomeb,nome);
        }
   }
   for (int i = 0; i < strlen(nomeb); i++){
       if(nomeb[i]>=97){
           nomeb[i]-=32;
       }
       printf("%c",nomeb[i]);
   }
   printf("\n");
   for (int i = 0; i < strlen(nomea); i++){
       if(nomea[i]>=97){
           nomea[i]-=32;
       }
       printf("%c",nomea[i]);
   }
   return 0;
}

