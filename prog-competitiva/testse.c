#include <stdio.h>
#include <string.h>


int main (){
    int **m=NULL;
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        m=(int**)realloc(m,i*sizeof(int*));
        for (int j = 1; j <= n; j++){
            m[i-1]= (int*)realloc(m[i-1],j*sizeof(int));
            scanf("%d",&m[i-1][j-1]);
            printf("voce digitou: %d i=%d j=%d\n",m[i-1][j-1],i,j);
        }
        printf("Chegou\n");
    }
    

}


