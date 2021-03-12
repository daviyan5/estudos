#include <stdio.h>
#include <stdlib.h>

void Sort(int v[], int n){
    for (int i = 1; i < n; i++){
        int j,p=v[i];
        for (j = i-1; j >= 0 && p < v[j] ; j--){
            v[j+1]=v[j];
        }
        v[j+1]=p;
    }
}

void moda(int v[], int n){
    int f[n],m[n],mf=0,ff=0;
    int a=0;
    m[0]=v[0];
    f[0]=1;
    for (int i = 1; i < n; i++){
        if(v[i]==m[a]) f[a]++;
        else{
            if(f[a]>ff){
                ff=f[a];
            }
            a++;
            f[a]=1;
            m[a]=v[i];
        }
    }
    if(f[a]>ff){
        ff=f[a];
    }
    for (int i = 0; ff>1 && i <= a; i++){
        if(f[i]==ff) printf("%d ",m[i]);
    }
    printf("\n");
}

void mediana(int v[], int n){
    if(n%2==0)printf("%g\n",(float)(v[n/2-1]+v[n/2])/2);
    else printf("%d\n",v[n/2]);
    return 0;
}


int estat(int caso){
    int n,maior,menor;
    float media=0;
    scanf("%d",&n);
    int v[n];
    menor=101;
    maior=-101;
    int i;
    for (i = 0; i < n; i++){
        scanf("%d",&v[i]);
        if(v[i]>maior) maior=v[i];
        if(v[i]<menor) menor=v[i];
        media+=v[i];
    }
    media=media/i; //%g
    Sort(v,n);
    printf("sequencia %d:\n",caso+1);
    for (int i = 0; i < n; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
    printf("%d %d\n",menor,maior);
    printf("%g\n",media);
    moda(v,n);
    mediana(v,n);
}



int main(){
   int n,i=0;
   scanf("%d",&n);
   while(i<n){
       estat(i);
       i++;
   }
   return 0;
}