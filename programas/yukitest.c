#include <string.h>
#include <stdio.h>

int main(){
    int c;
    scanf("%d",&c);
    char nomes[c][21];
    for (int i = 0; i < c; i++)
    {
        scanf("%s",nomes[i]);
    }
    int cont[c];
    for (int i = 0; i < c; i++){
            int len=strlen(nomes[i]);
            cont[i]=0;
            for (int j = 0; j < len; j++){
                if(nomes[i][j]>=97) nomes[i][j]-=32;
                cont[i]++;
            }
            nomes[i][len]='\0';
    }
    for (int i = 0; i < c; i++)
    {
        printf("%s %d %d\n",nomes[i],strlen(nomes[i]),cont[i]);
    }
}