#include <string.h>
#include <stdio.h>
typedef struct{
    char b[60][100];
    char v[60][100];
    int nb,nv;
}tP;
typedef struct{
    char b[60][100];
    char v[60][100];
    int nb,nv;
}tM;
typedef struct{
    char b[60][100];
    char v[60][100];
    int nb,nv;
}tG;
int main(){
    while(1){
        int n;
        scanf("%d",&n);
        if(n<=0) break;
        tP p;
        p.nb=0;
        p.nv=0;
        tM m;
        m.nb=0;
        m.nv=0;
        tG g;
        g.nb=0;
        g.nv=0;
        for (int i = 0; i < n; i++){
            char temp[100],cor[10],t;
            scanf("\n%[^\n]",temp);
            printf("nome=%s\n",temp);
            scanf("%s %c",cor,&t);
            if(t=='P'){
                if(cor[0]=='b'){
                    strcpy(p.b[p.nb],temp);
                    p.nb++;
                }
                else{
                    strcpy(p.v[p.nv],temp);
                    p.nv++;
                }
            }
            if(t=='M'){
                 if(cor[0]=='b'){
                    strcpy(m.b[m.nb],temp);
                    m.nb++;
                }
                else{
                    strcpy(m.v[m.nv],temp);
                    m.nv++;
                }
            }
            if(t=='G'){
                 if(cor[0]=='b'){
                    strcpy(g.b[g.nb],temp);
                    g.nb++;
                }
                else{
                    strcpy(g.v[g.nv],temp);
                    g.nv++;
                }
            }
        }
        for (int i = 0; i < p.nb; i++){
            for (int j = i; j < p.nb; j++){
                if(strcmp(p.b[i],p.b[j])>0){
                    char temp[100];
                    strcpy(temp,p.b[i]);
                    strcpy(p.b[i],p.b[j]);
                    strcpy(p.b[j],temp);
                }
            }
        }
        for (int i = 0; i < m.nb; i++){
            for (int j = i; j < m.nb; j++){
                if(strcmp(m.b[i],m.b[j])>0){
                    char temp[100];
                    strcpy(temp,m.b[i]);
                    strcpy(m.b[i],m.b[j]);
                    strcpy(m.b[j],temp);
                }
            }
        }
        for (int i = 0; i < g.nb; i++){
            for (int j = i; j < g.nb; j++){
                if(strcmp(g.b[i],g.b[j])>0){
                    char temp[100];
                    strcpy(temp,g.b[i]);
                    strcpy(g.b[i],g.b[j]);
                    strcpy(g.b[j],temp);
                }
            }
        }
        for (int i = 0; i < p.nv; i++){
            for (int j = i; j < p.nv; j++){
                if(strcmp(p.v[i],p.v[j])>0){
                    char temp[100];
                    strcpy(temp,p.v[i]);
                    strcpy(p.v[i],p.v[j]);
                    strcpy(p.v[j],temp);
                }
            }
        }
        for (int i = 0; i < m.nv; i++){
            for (int j = i; j < m.nv; j++){
                if(strcmp(m.v[i],m.v[j])>0){
                    char temp[100];
                    strcpy(temp,m.v[i]);
                    strcpy(m.v[i],m.v[j]);
                    strcpy(m.v[j],temp);
                }
            }
        }
        for (int i = 0; i < g.nv; i++){
            for (int j = i; j < g.nv; j++){
                if(strcmp(g.v[i],g.v[j])>0){
                    char temp[100];
                    strcpy(temp,g.v[i]);
                    strcpy(g.v[i],g.v[j]);
                    strcpy(g.v[j],temp);
                }
            }
        }
        for (int i = 0; i < p.nb; i++){
            printf("branco P %s\n",p.b[i]);
        }
        for (int i = 0; i < m.nb; i++){
            printf("branco M %s\n",m.b[i]);
        }
        for (int i = 0; i < g.nb; i++){
            printf("branco G %s\n",g.b[i]);
        }
        for (int i = 0; i < p.nv; i++){
            printf("vermelho P %s\n",p.v[i]);
        }
        for (int i = 0; i < m.nv; i++){
            printf("vermelho M %s\n",m.v[i]);
        }
        for (int i = 0; i < g.nv; i++){
            printf("vermelho G %s\n",g.v[i]);
        }
        printf("\n");
    }
    return 0;
}