#include <stdio.h>
#include <string.h>

int main(){
    int q,x,c,n,m,cact=0;
    scanf("%d %d %d %d %d",&q,&x,&c,&n,&m);
    char nomes[c+1][21];
    for (int i = 0; i < c; i++){
        scanf("%s",nomes[i]);
    }
    strcpy(nomes[c],"YUKI\0");
    for (int i = 0; i < c; i++){
        int len=strlen(nomes[i]);
        for (int j = 0; j < len; j++){
            if(nomes[i][j]>=97) nomes[i][j]-=32;
        }
        nomes[i][len]='\0';
    }
    for (int i = 0; i <=c; i++){
        printf("nome %d = %s\n",i,nomes[i]);
    }
    for (int p = 0; p < q; p++){
        char cac[n][m+1];
        int total=0;
        for (int i = 0; i < n; i++){
            scanf("%s",cac[i]);
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(cac[i][j]>=97) cac[i][j]-=32;
            }
            cac[i][m]='\0';
        }
        for (int i = 0; i < n; i++){
            printf("cac %d = %s\n",i,cac[i]);
        }
        for (int i = 0; i < n && total<=x; i++){
            for (int j = 0; j < m && total<=x; j++){
                for (int k = 0; k <= c && total<=x; k++){
                    if(cac[i][j]==nomes[k][0]){
                        int len=strlen(nomes[k]);
                        int cont=0,ach=0;
                        for (int p = j,d = 0; p < m && d < len && (m-j)>=len ; p++,d++){
                            printf("dir cac[%d][%d]=%c nome[%d][%d]=%c\n",i,p,cac[i][p],k,d,nomes[k][d]);
                            if(cac[i][p]==nomes[k][d]){
                                cont++;
                            }
                            else break;
                        }
                        if(cont==len) ach++;
                        cont=0;
                        printf("printf i=%d j=%d len=%d m=%d\n",i,j,len,m);
                        for (int p = j,d = 0; p >= 0 && d < len && j+1>=len ; p--,d++){
                            printf("esq cac[%d][%d]=%c nome[%d][%d]=%c\n",i,p,cac[i][p],k,d,nomes[k][d]);
                            if(cac[i][p]==nomes[k][d]){
                                cont++;
                            }
                            else break;
                        }
                        if(cont==len) ach++;
                        cont=0;
                        printf("printf i=%d j=%d len=%d n=%d\n",i,j,len,m);
                        for (int p = i,d = 0; p < n && d < len && (n-i)>=len ; p++,d++){
                            printf("baixo cac[%d][%d]=%c nome[%d][%d]=%c\n",p,j,cac[p][j],k,d,nomes[k][d]);
                            if(cac[p][j]==nomes[k][d]){
                                cont++;
                            }
                            else break;
                        }
                        if(cont==len) ach++;
                        cont=0;
                        for (int p = i,d = 0; p >= 0 && d < len && i+1>=len ; p--,d++){
                            printf("cima cac[%d][%d]=%c nome[%d][%d]=%c\n",p,j,cac[p][j],k,d,nomes[k][d]);
                            if(cac[p][j]==nomes[k][d]){
                                cont++;
                            }
                            else break;
                        }
                        if(cont==len) ach++;
                        cont=0;
                        total+=ach;
                        printf("Total: %d nome: %s i=%d j=%d\n",total,nomes[k],i,j);
                    }
                }
            }
        }
        if(total<=x) cact++;
    }
    printf("%d\n",cact);
    return 0;
}