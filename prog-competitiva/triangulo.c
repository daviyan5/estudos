#include <stdio.h>

int main(){
    char in,p='A',meio='A';
    scanf("%c",&in);
    int inic=in-65;
    for (int i = 0; i < inic+1; i++){
        for (int j = 0; j < inic-i; j++){
            printf(".");
        }
        for (int j = 0; j < i; j++){
            printf("%c",p);
            p++;
        }
        printf("%c",meio);
        meio++;
        for (int j = 0; j < i; j++){
            p--;
            printf("%c",p);
        }
        for (int j = 0; j < inic-i; j++){
            printf(".");
        }
        p='A';
        printf("\n");
    }
}