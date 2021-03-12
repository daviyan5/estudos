#include <stdio.h>
#include <string.h>
int main (){
   char pnome[10000];
   printf("Digite seu primeiro nome: ");
   scanf("%s",&pnome);
   if(pnome[strlen(pnome)-1]=='a'){
       printf("Bom dia,Sra.%s!\n",pnome);
   }
   else printf("Bom dia,Sr.%s!\n",pnome);
   return 0;
}

