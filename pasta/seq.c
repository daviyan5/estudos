#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    int n,t;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d",&t);
        long long int lista[t],decres[t],decresof[t];
        int a=0,to=0;
        for (int j = 0; j < t; j++){
            scanf("%lld",&lista[j]);
            if(j>0 && lista[j]<lista[j-1]){
                decres[a]=lista[j-1];
                decres[a+1]=lista[j];
                a++;
                printf("a=%d dec[a]=%lld dec[a+1]=%lld to=%d\n",a-1,decres[a-1],decres[a],to);
                if(j+1<t) continue;
            }
            if(a>to){
                to=a;
                for (int k = 0; k <= a; k++){
                    decresof[k]=decres[k];
                    printf("k=%d decof[k]=%lld\n",k,decresof[k]);
                }
                a=0;
            }
            else a=0;
        }
        if(to>0){
            printf("%d\n",to+1);
            for (int j = 0; j <= to; j++){
                printf("%lld ",decresof[j]);
            }
            printf("\n");
        }
        else printf("0\n");
    }
    return 0;
    
    

}