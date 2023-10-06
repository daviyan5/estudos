#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    scanf("root = [");
    int h=0,cont=0;
    char val;
    while(1){
        scanf("%c",&val);
        if(val==']'){
            break;
        }
        if(val==',' || val=='u' || val=='l'){
            continue;
        }
        cont++;
        if(cont==pow(2,h)){
            cont=0;
            h++;
        }
    }
    printf("%d",h);
    return 0;
}