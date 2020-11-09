#include <stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; i++){
        long long int n,s=0,soma1=0,naux,max=0,dif;
        scanf("%lld %d",&n,&s);
        printf("s=%d",s);
        naux=n;
        int j,rodou=1;
        for (j = 0; naux>0 ; j++){
            soma1+=naux%10;
            naux=naux/10;
        }
        int vN[j+1],vF[j+1];
        for (int h = 0; h<j+1; h++){
            vN[h]=0;
            vF[h]=0;
        }
        naux=n;
        for (int h=j; naux>0 ; h--){
            vN[h]=naux%10;
            naux=naux/10;
        }
        printf("soma1=%d j=%d\n",soma1,j);
        s=s;
        if(soma1<=s){
            dif=0;
        }
        else if(soma1>s){
            int casaZ;
            printf("s=%d",s);
            for (int h=1; s>0 || rodou; h++){
                printf("Rodou\n");
                s=s-vN[h];
                if(s<0){
                    vF[h]=vN[h]+s;
                    rodou=0;
                }
                else vF[h]=vN[h];
                casaZ=h;
            }
            printf("\nVetor 1:\n");
            for (int h=0 ; h<j+1  ; h++){
                printf("%d",vN[h]);
            }
            printf("\nVetor 2 antes:\n");
            for (int h=0 ; h<j+1  ; h++){
                printf("%d",vF[h]);
            }
            vF[casaZ]=0;
            printf("\nCasa Zerada=%d\n",casaZ);
            for (int h = casaZ-1; h>=0 ; h--){
                vF[h]++;
                if (vF[h]==10){
                    vF[h]=0;
                }
                else h=-1;
            }
            printf("Vetor 2 depois:\n");
            for (int h=0 ; h<j+1  ; h++){
                printf("%d",vF[h]);
            }
            printf("\n");
            for (int h = j; h >= 0; h--){
                long long int maux=vF[h];
                for (int k = 0; k <j-h && maux!=0 ; k++){
                    maux=maux*10;
                }
                max+=maux;
            }
            dif=max-n;
        }
        printf("%lld\n",dif);
    }
    return 0;
}