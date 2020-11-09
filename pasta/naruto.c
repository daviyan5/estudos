#include <stdio.h>
#include <string.h>
int main (){
   long long int n,a=0;
   scanf("%lld",&n);
   char tipos[5][n][n],ninja[100],carac[20];
   int sa=0,co=0,le=0,ma=0,ca=0;
   for (int i = 0; i < n; i++){
       scanf("%s %s",ninja,carac);
       if(!strcmp(carac,"Coragem") || !strcmp(carac,"Determinacao") || !strcmp(carac,"Conviccao")){
           strcpy(tipos[0][sa],ninja);
           a++;
           sa++;
           continue;
       }
       if(!strcmp(carac,"Ambicao") || !strcmp(carac,"Astucia") || !strcmp(carac,"Expertise")){
           strcpy(tipos[1][co],ninja);
           a++;
           co++;
           continue;
       }
       if(!strcmp(carac,"Analise") || !strcmp(carac,"Suporte") || !strcmp(carac,"Tecnica")){
           strcpy(tipos[2][le],ninja);
           a++;
           le++;
           continue;
       }
       if(!strcmp(carac,"Agilidade") || !strcmp(carac,"Inteligencia") || !strcmp(carac,"Destreza")){
           strcpy(tipos[3][ma],ninja);
           a++;
           ma++;
           continue;
       }
       if(!strcmp(carac,"Experiencia") || !strcmp(carac,"Perspicacia") || !strcmp(carac,"Pericia")){
           strcpy(tipos[4][ca],ninja);
           a++;
           ca++;
           continue;
       }
       if(i==n-1 && a==0){
           printf("Nao havera Jounins forte esse ano\n");
           return 0;
       }
   }
   if(n==0){
       printf("Nao havera Jounins forte esse ano\n");
       return 0;
   }
   printf("Sapos:\n");
   for (int i = 0; i < sa; i++){
       printf("- %s\n",tipos[0][i]);
   }
   printf("Cobras:\n");
   for (int i = 0; i < co; i++){
       printf("- %s\n",tipos[1][i]);
   }
   printf("Lesmas:\n");
   for (int i = 0; i < le; i++){
       printf("- %s\n",tipos[2][i]);
   }
   printf("Macacos:\n");
   for (int i = 0; i < ma; i++){
       printf("- %s\n",tipos[3][i]);
   }
   printf("Caes:\n");
   for (int i = 0; i < ca; i++){
       printf("- %s\n",tipos[4][i]);
   }

   return 0;
}

