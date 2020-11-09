#include <stdio.h>

int main(){
    int v1,v2,v3;
    char x,y;
    scanf("%d %c %d %c %d",&v1,&x,&v2,&y,&v3);
    if(x==y && x=='^'){
        if(v1 && v2 && v3) printf("1");
        else printf("0");
        return 0;
    }
    if(x==y && x=='v'){
        if(v1 || v2 || v3) printf("1");
        else printf("0");
        return 0;
    }
    if(x!=y && x=='^'){
        if(v1 && v2 || v3) printf("1");
        else printf("0");
        return 0;
    }
    if(x!=y && x=='v'){
        if(v1 || v2 && v3) printf("1");
        else printf("0");
    }
}