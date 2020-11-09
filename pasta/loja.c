#include <stdio.h>
#include <string.h>

typedef struct{
    int id;
    char nome[100];
    float preco;
}prod;
int main(){
    int n;
    scanf("%d",&n);
    prod p[n];
    for (int i = 0; i < n; i++){
        scanf("%d\n",&p[i].id);
        scanf("%[^\n]",p[i].nome);
        scanf("%f",&p[i].preco);
    }
    float total=0;
    while(1){
        int idt;
        scanf("%d",&idt);
        if(idt==0) break;
        int q;
        scanf("%d",&q);
        for (int i = 0; i < n && q>0; i++){
            if(p[i].id==idt){
                total+=q*p[i].preco;
            }
        }
    }
    printf("%d\n",total);

    
    
    

}