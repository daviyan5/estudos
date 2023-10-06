#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int eleve(int ex,int bas){
    long long int v=1;
    for (int i = 0; i < ex; i++){
        v=v*bas;
    }
    return v;
}

long long int converte(int n,int bx){
    int aux;
    long long int vd=0;
    for (int i = n-1; i >=0; i--){
        scanf("%d",&aux);
        if(aux!=0) vd+=aux*eleve(i,bx);
        else continue;
    }
    return vd;
}

int main(){
    int n,bx,m,by;
    scanf("%d %d",&n,&bx);
    long long int x=converte(n,bx);
    scanf("%d %d",&m,&by);
    long long int y=converte(m,by);
    printf("x=%lld y=%lld\n",x,y);
    printf("%c\n",x>y?'>':(x==y?'=':'<'));
}
