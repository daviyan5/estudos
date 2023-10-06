#include <string.h>
#include <stdio.h>

typedef struct{
    int id;
    float temp;
    char f;
}ambiente;
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        printf("TESTE %d\n",i+1);
        int m;
        scanf("%d",&m);
        ambiente p[m];
        int k=0;
        float media=0;
        for (k = 0; k < m; k++){
            scanf("%d %f %c",&p[k].id,&p[k].temp,&p[k].f);
            media+=p[k].temp;
        }
        media=media/k;
        for (k = 0; k < m; k++){
            if(p[k].f!='S' && p[k].temp<=1.15*media && p[k].temp<=40){
                continue;
            }
            else printf("%d\n",p[k].id);
        }
    }
    return 0;
}