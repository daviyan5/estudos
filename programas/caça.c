#include <stdio.h>
#include <string.h>

int main(){
    int q,x,c,n,m,cactotal=0;
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
    for (int i = 0; i < c; i++){
        printf("nome %d = %s\n",i,nomes[i]);
    }
    for (int p = 0; p < q; p++){
        char cac[n][m+1];
        int achei=0,total=0;
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
        for (int j = 0; j < n && achei==0; j++){ //linha
            for (int k = 0; k < m && achei==0; k++){ //coluna
                for (int a = 0; a <= c && achei==0; a++){ //nome
                    if (cac[j][k]==nomes[a][0]){
                        int cont=0,len;
                        len=strlen(nomes[a]);
                        printf("Entrou: %s\n",nomes[a]);
                        //direita
                        for (int b = k,d=0; b < m && d < len && (m-k)>=len; b++,d++){
                            if (cac[j][b]==nomes[a][d]){
                                if(d==len-1) cont++;
                                continue;
                            }
                            else break;
                        }
                        //esquerda
                        for (int b = k,d=0; b >=0 && d<len && k>=len ; b--,d++){
                            if (cac[j][b]==nomes[a][d]){
                                if(d==len-1) cont++;
                                continue;
                            }
                            else break;
                        }
                        //baixo
                        for (int b = j,d=0; b < n && d<len && (n-j)>=len; b++,d++){
                            if (cac[b][k]==nomes[a][d]){
                                if(d==len-1) cont++;
                                continue;
                            }
                            else break;
                        }
                        //cima
                        for (int b = j,d=0; b >=0 && d<len && j>=len; b--,d++){
                            if (cac[b][k]==nomes[a][d]){
                                if(d==len-1) cont++;
                                continue;
                            }
                            else break;
                        }
                        total+=cont;
                        if(cont>0) printf("Achou: %s em j=%d k=%d total=%d\n",nomes[a],j,k,total);
                    }
                    else continue;
                    if(total>=x) achei=1;
                }
            }
        }
        if(achei==0) cactotal++;
    }
    printf("%d\n",cactotal);
    return 0;
}