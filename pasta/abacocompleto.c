#include <stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; i++){
        int n,s,soma1=0,naux,max,dif;
        scanf("%d %d",&n,&s);
        naux=n;
        int j;
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
        printf("soma1=%d\n",soma1);
        if(soma1==s){
            max=n;
            dif=0;
        }
        else if(soma1>s){
            int casaZ,sobra;
            for (int h=1; s>0; h++){
                s=s-vN[h];
                if(s<0){
                    vF[h]=vN[h]+s;
                }
                else vF[h]=vN[h];
                casaZ=h;
            }
            printf("\nVetor 1:\n");
            for (int h=0 ; h<j+1  ; h++){
                printf("%d",vN[h]);
            }
            printf("\nVetor 2:\n");
            for (int h=0 ; h<j+1  ; h++){
                printf("%d",vF[h]);
            }
            sobra=vF[casaZ];
            vF[casaZ]=0;
            printf("\nCasa Zerada=%d\n",casaZ);
            for (int h = casaZ-1; h>=0 ; h--){
                vF[h]++;
                if (vF[h]==10){
                    vF[h]=0;
                    sobra+=9;
                }
                else h=-1;
            }
            printf("Sobra=%d\n",sobra);
            sobra--;
            for (int h = j; sobra>0; h--){
                vF[h]+=sobra;
                if (vF[h]>=10){
                    vF[h]=9;
                }
                sobra-=vF[h];
            } 
            printf("\nVetor 2:\n");
            for (int h=0 ; h<j+1  ; h++){
                printf("%d",vF[h]);
            }
        }
        printf("\n");
    }
    
    
    
    
    
    return 0;
}