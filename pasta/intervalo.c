#include <stdio.h>

int main(){
    int soma,pa=32767,pe=32767,co=32767;
    int pa0,pa1,pe0,pe1,co0,co1;
    scanf("%d %d %d %d %d %d %d",&soma,&pa0,&pa1,&co0,&co1,&pe0,&pe1);
    if (soma > pa1+pe1+co1 || soma < pa0+pe0+co0){
        printf("N\n");
        return 0;
    }
    for (int i = pa0; i <= pa1; i++){
        if(soma-i>=pe0){    
            for (int j = pe0; j <= pe1; j++){
                if (soma-j-i>=co0 && soma-j-i<=co1){ 
                    for (int k = co0; k <= co1; k++){
                        if(k==(soma-j-i)){
                            if(i<pa){
                                pa=i;
                                pe=j;
                                co=k;
                                break;
                            }
                            else if(j<pe){
                                pe=j;
                                co=k;
                                break;
                            }
                        }
                    }
                }    
           }
        }
    }
    printf("S\n%d %d %d\n",pa,co,pe);
}