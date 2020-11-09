#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int matriz[9][9],coluna[10][10],linha[10][10],reg[10][10];
    for (int i = 0; i < n; i++){
        int nao=0;
        for (int j = 0; j < 9; j++){
            for (int h = 0; h < 9; h++){
                scanf("%d",&matriz[j][h]);
            } 
        }
        for (int j = 0; j < 10; j++){
            for (int h = 0; h < 10; h++){
                linha[j][h]=0;
                coluna[j][h]=0;
                reg[j][h]=0;
            } 
        }
        for (int j = 0; j < 9; j++){
            for (int h = 0; h < 9; h++){
                int a;
                a=matriz[j][h];
                coluna[j][a]++;
            } 
        }
        for (int j = 0; j < 9; j++){
            for (int h = 0; h < 9; h++){
                int a;
                a=matriz[h][j];
                linha[j][a]++;
            } 
        }
        for (int j = 0; j < 9; j++){
            int b,c;
            if(j<3) b=0;
            else if(j<6) b=3;
            else if(j<9) b=6;
            if(j%3==0) c=0;
            else if(j%3==1) c=3;
            else if(j%3==2) c=6;
            for (int h = b; h < b+3; h++){
                for(int k= c; k < c+3; k++){
                    int a=matriz[h][k];
                    reg[j][a]++;
                }
            } 
        }
        printf("linhas:\n");
        for (int j = 0; j < 9; j++){
            for (int h = 1; h < 10; h++){
                printf("%d ",linha[j][h]);
            }
            printf("\n");
        }
        printf("colunas:\n");
        for (int j = 0; j < 9; j++){
            for (int h = 1; h < 10; h++){
                printf("%d ",coluna[j][h]);
            }
            printf("\n");
        }
        printf("regioes:\n");
        for (int j = 0; j < 9; j++){
            for (int h = 1; h < 10; h++){
                printf("%d ",reg[j][h]);
            }
            printf("\n");
        }
        for (int j = 0; j < 9 && nao==0; j++){
            for (int h = 1; h < 10 && nao==0; h++){
                if(linha[j][h]!=1||coluna[j][h]!=1||reg[j][h]!=1) nao=1;
                if(nao==1) printf("j=%d h=%d\n",j,h);
            } 
        }
        printf("Instancia %d\n",i+1);
        if(nao==1) printf("NAO\n");
        else printf("SIM\n");
        printf("\n");
    }
    
}