#include <stdio.h>
#include <stdlib.h>
#define TAM 10
int main() {
    int *vet = NULL, i;
    vet = (int *) realloc(vet, TAM * sizeof(int));
    if(vet!=NULL) {
        for(i=0; i<TAM; i++)
            vet[i] = i;
            printf("%d\n",vet[i]);
        free(vet);
    }
    return 0;
}
