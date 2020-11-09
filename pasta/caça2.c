#include <stdio.h>
#include <string.h>
int main (){
    int q,x,c,n,m,cactotal=0;
    scanf("%d %d %d %d %d",&q,&x,&c,&n,&m);
    char nomes[c+2][21];
    for (int i = 1; i <= c; i++){
        scanf("%s",nomes[i]);
        printf("%s\n",nomes[i]);
    }
    strcpy(nomes[c+1],"YUKI");
    for (int j = 1; j <= c; j++){ //converte cada char pra maiuscula
            for (int k = 0; k < strlen(nomes[j]); k++){
                if(nomes[j][k]>=97) nomes[j][k]-=32;
            }
    }
    for (int p = 0; p < q; p++){
        char aux[n][m],cac[n][m];
        int achei=0,total=0;
        for (int i = 0; i < n; i++){
            scanf("%s",&aux[i]);
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cac[i][j]=aux[i][j];
            }
        }
        for (int i = 0; i < n; i++){ //converte cada char pra maiuscula
            for (int j = 0; j < m; j++){
                if(cac[i][j]>=97) cac[i][j]-=32;
            }
        }
        for (int j = 0; j < n && achei==0; j++){ //linha
            for (int k = 0; k < m && achei==0; k++){ //coluna
                for (int a = 1; a <= c+1 && achei==0; a++){ //nome
                    if (cac[j][k]==nomes[a][0]){
                        printf("linha=%s nome=%s\n",cac[j],nomes[a]);
                        int cont=0,len;
                        len=strlen(nomes[a]);
                        //direita
                        for (int b = k,d=0; b < m && d<len && (m-k)>=len; b++,d++){
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
                        if(cont>0) printf("total=%d palavra=%s pos j=%d k=%d\n",total,nomes[a],j,k);
                    }
                    else continue;
                    if(total>x) achei=1;
                }
            }
        }
        if(achei==0) cactotal++;
    }
    printf("%d",cactotal);
    return 0;


}

