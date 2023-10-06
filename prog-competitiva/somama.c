#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int m1[n][n],m2[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d",&m1[i][j]);
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d",&m2[i][j]);
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d\n",m1[j][i]+m2[j][i]);
        }
    }
}