#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf("%d",&n);
    int vOri[n],vOrd[n];
    for (int i = 0; i < n; i++){
        scanf("%d",&vOri[i]);
        vOrd[i]=vOri[i];
    }
    for (int i = 1; i < n; i++){
        for (int j = i; vOrd[j]<vOrd[j-1] && j>0 ; j--){
            int aux;
            aux=vOrd[j];
            vOrd[j]=vOrd[j-1];
            vOrd[j-1]=aux;
        }
    }
    int t=0,pos[n],num[n];
    for (int i = 0; i < n; i++){
        if(vOrd[i]==vOri[i]){
            t++;
            pos[i]=i+1;
            num[i]=vOrd[i];
        }
        else{
            pos[i]=-1;
            num[i]=-1;
        }
    }
    printf("%d\n",t);
    for (int i = 0; i < n; i++){
        if(pos[i]>=0){
            printf("%d %d\n",num[i],pos[i]);
        }
    }
    
    
    
    return 0;
    
    

}