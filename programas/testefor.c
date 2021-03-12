#include <stdio.h>
#include <string.h>
int main (){
    char data[10000][101];
    for (int i = 0; i < 10000; i++){
        for (int j = 0; j < 100; j++){
            data[i][j]=0;
        }
        data[i][100]='/0';
    }
    printf("cavou\n");
    return 0;
}

