#include <stdio.h>
#include <string.h>
char string[100], string2[100];
int d, i, j, k = 0, tamanho = 0, tamanho2 = 0, aux = 0;
int main() {
    fgets(string,100,stdin);
    fgets(string2,100,stdin);
    tamanho = strlen(string);
    tamanho2 = strlen(string2);
    for(i = 0; i < tamanho; i++){
        printf("%c %c\n",string[i],string2[0]);
        printf("%d %d\n",tamanho2,tamanho);
        for(j = 1, d = i; j < tamanho2 && d < tamanho; j++, d++){
            if(string[d]==string2[j]){
                if(d==tamanho-1) k++;
            }
            else{
                break;
            }
        }
    }
    printf("%d", k);
    return 0;
}