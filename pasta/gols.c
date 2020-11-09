#include <stdio.h>

int main() {
    int t1,t2,t3;
    scanf("%d %d %d",&t1,&t2,&t3);
    if (t1<0 || t2<0 || t3<0){
        printf("esses dados nao valem");
        return 0;
    }
    if(t2-t1<=t3-t2) printf(":)");
    else printf(":(");
}