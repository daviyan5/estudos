#include <stdio.h>
#include <string.h>
#include <math.h>

int mdc(int x,int y){
    if(y==0){
        return x;
    }
    return mdc(y,x%y);

}
int div(int x){
    int a[x],n=0;
    int count=sqrt(x)+1;
    for (int i = 2; i < count; i++){
        if(x%i==0){
            int primo=1;
            int count2=sqrt(i)+1;
            for (int j = 2; j < count2; j++){
                if(i%j==0){
                    primo=0;
                    break;
                }
            }
            if(primo==1){
                a[n]=i;
                n++;
            }
        }
    }
    int res=1;
    for (int i = 0; i < n; i++){
        if(x/a[i]<x/res){
            res=a[i];
        }
    }
    return res;
}


int main (){
    int x,y;
    scanf("%d %d",&x,&y);
    int d=mdc(x,y);
    if(d==1) printf("-1\n");
    else printf("%d\n",div(d));
}

