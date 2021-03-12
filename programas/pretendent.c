#include <stdio.h>
#include <string.h>
int main (){
   int n,m;
   scanf("%d %d\n",&n,&m);
   char matriz[n][m];
   for (int i = 0; i < n; i++){
       for (int j = 0; j < m; j++){
           scanf("%s",&matriz[i][j]);
       }
   }
   int t;
   scanf("%d",&t);
   for (int i = 0; i < t; i++){
       char di[9];
       int x,y,ponto;
       scanf("%d %d",&x,&y);
       scanf("%s",&di);
       scanf("%d",&ponto);
       if(di[0]=='c'){
           for (int i = x; i >= 0 && ponto>0; i--){
               if(matriz[i][y]=='#') ponto--;
               else ponto-=2;
           } 
       }
       else if (di[0]=='b'){
           for (int i = x; i < n && ponto>0; i++){
               if(matriz[i][y]=='#') ponto--;
               else ponto-=2;

           } 
       }
       else if(di[0]=='e'){
           for (int i = y; i >= 0 && ponto>0; i--){
               if(matriz[x][i]=='#') ponto--;
               else ponto-=2;
                             
           } 
       }
       else{
           for (int i = y; i < m && ponto>0; i++){ 
               if(matriz[x][i]=='#') ponto--;
               else ponto-=2;
           } 
       }
       if(ponto>0) printf("O amor est� no ar!\n");
       else printf("Vou voltar pra Limoeiro...\n");
   }
   
   return 0;
}

