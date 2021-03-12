#include <stdio.h>
#include <string.h>
int main (){
   char pnome[10000],unome[10000],s,esp;
   printf("Digite seu primeiro nome: ");
   scanf("%s",&pnome);
   printf("Digite seu ultimo nome: ");
   scanf("%s",&unome);
   printf("Digite seu sexo: ");
   scanf("\n%c",&s);
   if(s=='F'){
       printf("Sra.%s, %s\n",unome,pnome);
   }
   else printf("Sr.%s, %s\n",unome,pnome);
   return 0;
}

