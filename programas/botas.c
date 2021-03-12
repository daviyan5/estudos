#include <stdio.h>

int main(){
    int t,n=0,m;
    char l;
    for(;n!=-1;){
        int vD[61],vE[61];
        for (int i=30;i<=60;i++){
            vD[i]=0;
            vE[i]=0;
        }
        scanf("%d",&n);
        if(n==-1) break;
        for(int i=0;i<n;i++){
            scanf("%d %d",&m,&l);
            if (l=='E') vE[m]++;
            else vD[m]++;
        }
        t=0;
        for (int i=30;i<=60;i++){
            if (vD[i]>vE[i]) t += vE[i];
            else t += vD[i];
        }
        printf("%d\n",t);
    }
}