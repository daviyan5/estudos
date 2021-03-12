#include <stdio.h>
#include <math.h>

int main(){
    int n,a;
    scanf("%d %d",&n,&a);
    int vMax[n],vMin[n],vNorm[n],p;
    for (int i = 0; i < n; i++){
        vMax[i]=0;
        vMin[i]=1001;
    }
    for (int i = 0; i < a; i++){
        for(int j=0; j < n;j++){
            int aux;
            scanf("%d",&aux);
            if(aux>vMax[i]) vMax[j]=aux;
            if(aux<vMin[i]) vMin[j]=aux;
        }
    }
    for (int i = 0; i < n; i++){
        scanf("%d",&vNorm[i]);
        vNorm[i]=(vNorm[i]-vMin[i])*(1000)/(vMax[i]-vMin[i]);
        if(vNorm[i]<0) vNorm[i]=0;
        if(vNorm[i]>1000) vNorm[i]=1000;
        vNorm[i]=1000-vNorm[i];
    }
    int num=0,den=0;
    for (int i = 0; i < n; i++){
        num=num+i*vNorm[i];
        den=den+vNorm[i];
    }
    for (int i = 0; i < n; i++){
        printf("%d ",vMax[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%d ",vMin[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%d ",vNorm[i]);
    }
    printf("\n%d\n",num/den);
}