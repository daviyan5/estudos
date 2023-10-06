#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 0 
#define L 1 
#define S 2 
#define O 3
#define NE 4 
#define SE 5 
#define SO 6 
#define NO 7


typedef struct{
    int linha;
    int coluna;
    int direc;

} Encontradas;
Encontradas *vetEnc=NULL;
int procPalavra(char **matriz, char pal[][30], int t,int n){
    int enc=0;
    enc=procN(matriz,pal,t,n,enc);
    enc=procL(matriz,pal,t,n,enc);
    enc=procS(matriz,pal,t,n,enc);
    enc=procO(matriz,pal,t,n,enc);
    enc=procNE(matriz,pal,t,n,enc);
    enc=procSE(matriz,pal,t,n,enc);
    enc=procSO(matriz,pal,t,n,enc);
    enc=procNO(matriz,pal,t,n,enc);
    printf("Enc=%d\n",enc);
    return enc;
}

int procN(char **matriz, char pal[][30], int t,int n, int enc){
    for (int i = 0; i < t; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if (matriz[j][k]==pal[i][0]){
                    int len=strlen(pal[i]);
                    int foi=1;
                    int cont=0;
                        for (int p = j,d = 0; p >= 0 && d < len && j+1>=len && foi; p--,d++){
                            if(matriz[p][k]==pal[i][d]){
                                cont++;
                            }
                            else foi=0;
                        }
                        if(cont==len){
                            vetEnc = (Encontradas*)realloc(vetEnc,(enc+1)*sizeof(Encontradas));
                            vetEnc[enc].coluna=k;
                            vetEnc[enc].linha=j;
                            vetEnc[enc].direc=N;
                            enc++;
                        };
                }
            }
        }
        
    }
    return enc;
}

int procL(char **matriz, char pal[][30], int t,int n,int enc){
    for (int i = 0; i < t; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if (matriz[j][k]==pal[i][0]){
                    int len=strlen(pal[i]);
                    int foi=1;
                    int cont=0;
                        for (int p = k,d = 0; p < n && d < len && n-(k)>=len && foi; p++,d++){
                            if(matriz[j][p]==pal[i][d]){
                                cont++;
                            }
                            else foi=0;
                        }
                        if(cont==len){
                            vetEnc = (Encontradas*)realloc(vetEnc,(enc+1)*sizeof(Encontradas));
                            vetEnc[enc].coluna=k;
                            vetEnc[enc].linha=j;
                            vetEnc[enc].direc=L;
                            enc++;
                        };
                }
            }
        }
        
    }
    return enc;
}

int procS(char **matriz, char pal[][30], int t,int n,int enc){
for (int i = 0; i < t; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if (matriz[j][k]==pal[i][0]){
                    int len=strlen(pal[i]);
                    int foi=1;
                    int cont=0;
                        for (int p = j,d = 0; p < n && d < len && n-j>=len && foi; p++,d++){
                            if(matriz[p][k]==pal[i][d]){
                                cont++;
                            }
                            else foi=0;
                        }
                        if(cont==len){
                            vetEnc = (Encontradas*)realloc(vetEnc,(enc+1)*sizeof(Encontradas));
                            vetEnc[enc].coluna=k;
                            vetEnc[enc].linha=j;
                            vetEnc[enc].direc=S;
                            enc++;
                        };
                }
            }
        }
        
    }
    return enc;}

int procO(char **matriz, char pal[][30], int t,int n,int enc){
for (int i = 0; i < t; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if (matriz[j][k]==pal[i][0]){
                    int len=strlen(pal[i]);
                    int foi=1;
                    int cont=0;
                        for (int p = k,d = 0; p >=0 && d < len && k+1>=len && foi; p--,d++){
                            if(matriz[j][p]==pal[i][d]){
                                cont++;
                            }
                            else foi=0;
                        }
                        if(cont==len){
                            vetEnc = (Encontradas*)realloc(vetEnc,(enc+1)*sizeof(Encontradas));
                            vetEnc[enc].coluna=k;
                            vetEnc[enc].linha=j;
                            vetEnc[enc].direc=O;
                            enc++;
                        };
                }
            }
        }
        
    }
    return enc;}

int procNE(char **matriz, char pal[][30], int t,int n,int enc){
for (int i = 0; i < t; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if (matriz[j][k]==pal[i][0]){
                    int len=strlen(pal[i]);
                    int foi=1;
                    int cont=0;
                        for (int p = j,l = k,d = 0; p < n && l < n && d < len && j+1>=len && n-k>=len && foi; p--,l++,d++){
                            if(matriz[p][l]==pal[i][d]){
                                cont++;
                            }
                            else foi=0;
                        }
                        if(cont==len){
                            vetEnc = (Encontradas*)realloc(vetEnc,(enc+1)*sizeof(Encontradas));
                            vetEnc[enc].coluna=k;
                            vetEnc[enc].linha=j;
                            vetEnc[enc].direc=NE;
                            enc++;
                        };
                }
            }
        }
        
    }
    return enc;}

int procSE(char **matriz, char pal[][30], int t, int n,int enc){
for (int i = 0; i < t; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if (matriz[j][k]==pal[i][0]){
                    int len=strlen(pal[i]);
                    int foi=1;
                    int cont=0;
                        for (int p = j,l = k,d = 0; p < n && l < n && d < len && n-j>=len && n-k>=len && foi; p++,l++,d++){
                            if(matriz[p][l]==pal[i][d]){
                                cont++;
                            }
                            else foi=0;
                        }
                        if(cont==len){
                            vetEnc = (Encontradas*)realloc(vetEnc,(enc+1)*sizeof(Encontradas));
                            vetEnc[enc].coluna=k;
                            vetEnc[enc].linha=j;
                            vetEnc[enc].direc=SE;
                            enc++;
                        };
                }
            }
        }
        
    }
    return enc;}

int procSO(char **matriz, char pal[][30], int t, int n,int enc){
for (int i = 0; i < t; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if (matriz[j][k]==pal[i][0]){
                    int len=strlen(pal[i]);
                    int foi=1;
                    int cont=0;
                        for (int p = j,l = k,d = 0; p < n && l < n && d < len && n-j>=len && k+1>=len && foi; p++,l--,d++){
                            if(matriz[p][l]==pal[i][d]){
                                cont++;
                            }
                            else foi=0;
                        }
                        if(cont==len){
                            vetEnc = (Encontradas*)realloc(vetEnc,(enc+1)*sizeof(Encontradas));
                            vetEnc[enc].coluna=k;
                            vetEnc[enc].linha=j;
                            vetEnc[enc].direc=SO;
                            enc++;
                        };
                }
            }
        }
        
    }
    return enc;}

int procNO(char **matriz, char pal[][30], int t, int n,int enc){
for (int i = 0; i < t; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if (matriz[j][k]==pal[i][0]){
                    int len=strlen(pal[i]);
                    int foi=1;
                    int cont=0;
                        for (int p = j,l = k,d = 0; p < n && l < n && d < len && j+1>=len && k+1>=len && foi; p--,l--,d++){
                            if(matriz[p][l]==pal[i][d]){
                                cont++;
                            }
                            else foi=0;
                        }
                        if(cont==len){
                            vetEnc = (Encontradas*)realloc(vetEnc,(enc+1)*sizeof(Encontradas));
                            vetEnc[enc].coluna=k;
                            vetEnc[enc].linha=j;
                            vetEnc[enc].direc=NO;
                            enc++;
                        };
                }
            }
        }
        
    }
    return enc;
}

char **leMatriz(char **matriz, FILE *arquivo, int n){
    matriz=(char**)malloc(n*sizeof(char*));
    for (int i = 0; i < n; i++){
        matriz[i] = (char*)malloc(n*sizeof(char));
        if(matriz[i]==NULL){
            printf("Erro de memória/leitura!\n");
            exit(1);
        }
        for (int j = 0; j < n; j++){
            fscanf(arquivo,"%c\n",&matriz[i][j]);
        }
        printf("%s\n",matriz[i]);
    }
    return matriz;
}

int main(){
    char **matriz;
    FILE *arquivo;
    arquivo = fopen("/home/davi/Documentos/testeIP.txt","r");
    if(arquivo==NULL) {
        printf("Deu ruim!\n");
        exit(1);
    }
    else printf("Foi!\n");
    int n;
    fscanf(arquivo,"%d\n",&n);
    matriz=leMatriz(matriz,arquivo,n);
    int m=ftell(arquivo);
    fseek(arquivo,0,SEEK_END);
    int f=ftell(arquivo);
    char vetorAux[f-m+1];
    fseek(arquivo,m,SEEK_SET);
    fread(vetorAux,sizeof(char),f-m,arquivo);
    vetorAux[f-m]='\0';
    int t=0,p=0;
    for (int i = 0; i < f-m+1; i++){
        if(vetorAux[i]=='\n') t++;
    }
    char vetPal[t][30];
    for (int i = 0; i <= t; i++){
        int esp=1;
        for (int j = 0; p < f-m+1 && esp; j++){
            if(vetorAux[p]=='\n') {
                esp=0;
                vetPal[i][j]='\0';
            }
            else{
                vetPal[i][j]=vetorAux[p];
            }
            p++;
        }
        printf("%s\n",vetPal[i]);
    }
    int total=procPalavra(matriz,vetPal,t,n);
    FILE *resultado;
    resultado=fopen("/home/davi/Documentos/resultado.bin","w");
    if(resultado==NULL){
        printf("Deu ruim na abertura!\n");
        exit(1);
    }
    if(vetEnc==NULL){
        printf("Deu ruim na função!\n");
        exit(1);
    }
    printf("Total=%d\n",total);
    fwrite(vetEnc,total,total*sizeof(Encontradas),resultado);
    fclose(resultado);
    fclose(arquivo);
    free(vetEnc);
    free(matriz);
    return 0;
}