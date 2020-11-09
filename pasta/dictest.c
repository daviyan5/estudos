#include <stdio.h>
#include <string.h>
int main (){
   int m,n;
   for(int z=0;z==z;z++){
       scanf("%d %d",&m,&n);
       if(m==0 && n==0) break;
       char tr[m][100],tr2[m][100],of[500];

       for (int i = 0; i < m; i++){
           strcpy(tr[i]," ");
           strcpy(tr2[i]," ");
           scanf("%s -> %s\n",tr[i],tr2[i]);
       }
       for (int i = 0; i < n; i++){
           fgets(of,400,stdin);
           int len=strlen(of)-1,a=0,b=0;
           if(of[len]=='\n') of[len]='\0';
           char pal[len][500];
           for (int j = 0; j <= len; j++){
               if(of[j]==' '){
                   a=0;
                   b++;
               }
               else{
                   pal[b][a]=of[j];
                   a++;
               }
           }
           int len2[b];
           for (int j = 0; j <= b; j++){
               len2[j]=strlen(pal[j]);
               for (int k = 0; k < len2[j]; k++){
                   for (int a = 0; a < m; a++){
                       if(pal[j][k]==tr[a][0]){
                           char len3=strlen(tr[a]);
                           int cont=0;
                           for (int q = k; q < len3+k; q++){
                               if(pal[j][q]==tr[a][q-k]) cont++;
                               else break;
                           }
                           if(cont==len3){
                               int len4=strlen(tr2[a]);
                               if(len4>len3){
                                   for(int q=len2[j]+len4-len3; q>=len4;q--){
                                       pal[j][q]=pal[j][q-(len4-len3)];
                                   }
                                   len2[j]=len2[j]+len4-len3;
                               }
                               if(len4<len3){
                                   for(int q= k+len4; q<=len2[j]-len3+len4;q++){
                                       pal[j][q]=pal[j][q+(len3-len4)];
                                   }
                                   len2[j]=len2[j]+len4-len3;
                               }
                               for(int q=k; q<k+len4;q++){
                                   pal[j][q]=tr2[a][q-k];
                                }
                                k=k+len4;
                           }
                       }
                   }
               }
           }
            for (int j = 0; j <= b; j++){
               for(int k=0;k < len2[j];k++){
                   printf("%c",pal[j][k]);
               }
               if(j<b) printf(" ");
               else printf("\n");
           }
       }
   }
   
}

