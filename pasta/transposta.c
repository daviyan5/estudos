#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int matriz[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("Escreva o elemento da linha %d e coluna %d (menores que 1000 pra ficar bonitinho): ",i,j);
            scanf("%d",&matriz[i][j]);
        }
        
    }
    printf("\nDigitada:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%03d ",matriz[i][j]);
        }
        printf("\n");
    }
    printf("\nTransposta:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%03d ",matriz[j][i]);
        }
        printf("\n");
    }
}