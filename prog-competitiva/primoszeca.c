#include <stdio.h>
#include <math.h>

int main(){
    int a,b,n=0,p1=0,p2=0,p3=0,pi=0,pf=0;
    scanf("%d %d",&a,&b);
    if(a==3) a=4;
    for (int i = a-1; i > 1 && pi==0; i--){
        if(i%2==0) continue;
        for (int j = 2; j <= i/2; j++){
            if(j%2==0 && j!=i/2) continue;
            if(i%j==0) break;
            else if (j==i/2) pi=i;
            
        }
        if(i==3) pi=3;
        if(pi!=0) break;
    }
    for (int i = b+1; pf==0 ; i++){
        if(i%2==0) continue;
        for (int j = 2; j <= i/2; j++){
            if(j%2==0 && j!=i/2) continue;            
            if(i%j==0) break;
            else if (j==i/2) pf=i;
        }
        if(pf!=0) break;
    }
    printf("pi=%d pf=%d\n",pi,pf);
    for (int i = pi; i <=pf; i++){
        if(i%2==0) continue;
        for (int j = 2; j <= i/2; j++){
            if(j%2==0 && j!=i/2) continue;
            if(i%j==0) break;
            else if (j==i/2){
                if (p1==0) p1=i;
                else if (p2==0) p2=i;
                else p3=i;
            }
        }
        if(i==3) p1=3;
        if(p1!=0 && p2!=0 && p3!=0){
            if(p2==i){
                if(2*p1==p2+p3){
                    n++;
                    printf("p1=%d p2=%d p3=%d\n",p1,p2,p3);
                }
                p3=0;
            }
            if(p3==i){
                if(2*p2==p3+p1) {
                    n++;
                    printf("p1=%d p2=%d p3=%d\n",p1,p2,p3);
                }
                p1=0;
            }
            if(p1==i){
                if(2*p3==p2+p1){
                    n++;
                    printf("p1=%d p2=%d p3=%d\n",p1,p2,p3);
                }
                p2=0;
            }
        }
    }
    
    
    printf("%d\n",n);
    
    return 0;
}