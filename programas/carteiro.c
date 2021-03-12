#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    char l[3];
    scanf("%c %c %c",&l[0],&l[1],&l[2]);
    if(l[0]<65 || l[0]>90 || l[1]<65 || l[1]>90 || l[2]<65 || l[2]>90){
        printf("Etiquetas erradas!");
        return 0;
    }
    if(l[0]>l[1]){
        int temp;
        temp=l[0];
        l[0]=l[1];
        l[1]=temp;
    }
    if(l[0]>l[2]){
        int temp;
        temp=l[0];
        l[0]=l[2];
        l[2]=temp;
    }
    if(l[1]>l[2]){
        int temp;
        temp=l[1];
        l[1]=l[2];
        l[2]=temp;
    }
    bool vog=false;
    int n;
    for (int i = 0; i < 3; i++){
       n=l[i];
       if(n==65 || n==69 || n==73 || n==79 || n==85) vog=true;
    }
    if(vog){
        if(l[1]-l[0]==l[2]-l[1]){
            int dif=l[1]-l[0];
            if(dif==1) printf("Sequência quase perfeita.");
            if(dif==2) printf("Bissequência quase perfeita.");
            if(dif==3) printf("Trissequência quase perfeita.");
        }
        else printf("Só umas letras ai...");
    }
    else{
        if(l[1]-l[0]==l[2]-l[1]){
            int dif=l[1]-l[0];
            if(dif==1) printf("Sequência perfeita.");
            if(dif==2) printf("Bissequência perfeita.");
            if(dif==3) printf("Trissequência perfeita.");
        }
        else printf("Só umas letras ai...");
    }
    return 0;
}