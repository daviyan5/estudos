#include <stdio.h>
#include <string.h>
int main (){
   int m,n;
   while (m!=0 && n!=0){
       printf("Digite m e n:\n");
       scanf("%d %d",&m,&n);
       char tr[m][100],tr2[m][100],of[500];
       for (int i = 0; i < m; i++){
           scanf("%s -> %s\n",tr[i],tr2[i]);
           printf("%s -> %s\n",tr[i],tr2[i]);
       }
       printf("saiu\n");
       for (int i = 0; i < n; i++){
           fgets(of,500,stdin);
           int len=strlen(of)-1,a=0,b=0;
           if(of[len]=='\n') of[len]='\0';
           printf("aqui=%s len=%d\n",of,len);
           char pal[len][500];
           for (int j = 0; j <= len; j++){
               if(of[j]==' ' || j==len){
                   a=0;
                   b++;
               }
               else{
                   pal[b][a]=of[j];
                   printf("of[j]=%c pal[b][a]=%c\n",of[j],pal[b][a]);
                   a++;
                   
               }
           }
           for (int j = 0; j <= b; j++){
               printf("linha=%s\n",pal[j]); 
           }
           int len2[b];
           for (int j = 0; j <= b; j++){
               len2[j]=strlen(pal[j]);
               for (int k = 0; k < len2[j]; k++){
                   for (int a = 0; a < m; a++){
                       printf("j=%d len2=%d k=%d a=%d pal[%d][%d]=%c tr[%d][0]=%c\n",j,len2[j],k,a,j,k,pal[j][k],a,tr[a][0]);
                       if(pal[j][k]==tr[a][0]){
                           printf("iniciais iguais\n");
                           char len3=strlen(tr[a]);
                           printf("len3=%d\n",len3);
                           int cont=0;
                           for (int q = k; q < len3+k; q++){
                               printf("pal[%d][%d]=%c tr[%d][%d]=%c\n",j,q,pal[j][q],a,q-k,tr[a][q-k]);
                               if(pal[j][q]==tr[a][q-k]) cont++;
                               else break;
                           }
                           if(cont==len3){
                               int len4=strlen(tr2[a]);
                               printf("len4=%d\n",len4);
                               printf("linha=%s\n",pal[j]);
                               if(len4>len3){
                                   for(int q=len2[j]+len4-len3-1; q>=len4;q--){
                                       pal[j][q]=pal[j][q-(len4-len3)];
                                   }
                                   len2[j]=len2[j]+len4-len3;
                               }
                               if(len4<len3){
                                   for(int q= k+len4; q<=len2[j]-len3+len4;q++){
                                       pal[j][q]=pal[j][q+(len3-len4)];
                                   }
                                   for(int q=k; q<k+len4;q++){
                                        pal[j][q]=tr2[a][q-k];
                                    }   
                                   len2[j]=len2[j]+len4-len3;
                               }
                               printf("linha=%s\n",pal[j]);
                               for(int q=k; q<k+len4;q++){
                                   pal[j][q]=tr2[a][q-k];
                                }
                                printf("linha=%s\n",pal[j]);
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

