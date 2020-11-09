#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int a, n;
    scanf("%d", &n);
    scanf("%d", &a);
    int vetor[n][a];
    int max[n];
    int min[n];
    
    for (int i=0; i<n;i++){
        max[i]=0;
    }for (int i=0; i<n;i++){
        min[i]=1000;
    }
    for(int i=0 ; i<a; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&vetor[j][i]);
            printf("vetor[%d][%d]=%d\n",j,i,vetor[j][i]);

        }
    }for(int i=0; i<n;i++){
        int aux=0;
        for(int j=0; j<a;j++){
            aux = vetor[j][i];
            if(aux> max[j]){
                max[j]=aux;
            }
        }
    }for(int i=0; i<n;i++){
        int aux=10000;
        for(int j=0; j<a;j++){
            aux = vetor[j][i];
            if(aux< min[j]){
                min[j]=aux;
            }
        }
    }
    for(int i=0; i<n; i++){
        printf("%d ", max[i]);
    }
    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d ", min[i]);
    }
    int teste[n];
    for(int i=0; i<n;i++){
        scanf("%d", &teste[i]);
    }
    
    
	return 0;
}