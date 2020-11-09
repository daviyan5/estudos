#include <stdio.h>
#include <string.h>
int main (){
    char le[100],num[100];
    scanf("%s %s",num,le);
    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; i++){
        char aux[100];
        scanf("%s",aux);
        for (int i = 0; i < strlen(aux); i++){
            if(aux[i]<=57){
                int a;
                for (int j = 0; j < strlen(num); i++){
                    if(num[j]==aux[i]){
                        a=j;
                        break;
                    }
                }
                aux[i]=le[a];
            }
        }
        printf("%s\n",aux);
    }
}

