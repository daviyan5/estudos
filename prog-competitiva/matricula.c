#include <string.h>
#include <stdio.h>

typedef struct{
    char codig[30];
    char nome[500];
    int idade;
    int sexo;
    float nota;
}alunos;

typedef struct{
    char codig[25];
    char nome[100];
    char matric[1000][500];
    int nma;
    int ordem;
}materias;

int main(){
    int n,qtM=0,qtF=0,nE=0;
    float medI=0,medIE=0;
    scanf("%d\n",&n);
    alunos a[n];
    for (int i = 0; i < n; i++){
        scanf("%s\n",a[i].codig);
        scanf("%[^\n]",a[i].nome);
        scanf("%d",&a[i].idade);
        scanf("%d",&a[i].sexo);
        scanf("%f",&a[i].nota);
        if(a[i].sexo==1) qtM++;
        else qtF++;
        medI+=a[i].idade;
        if(a[i].nota>7.5) {
            medIE+=a[i].idade;
            nE++;
        }
    }
    medI=medI/n;
    medIE=medIE/nE;
    int m;
    scanf("%d",&m);
    materias d[m];
    for (int i = 0; i < m; i++){
        scanf("%s\n",d[i].codig);
        scanf("%[^\n]",d[i].nome);
        d[i].nma=0;
        d[i].ordem=i;
    }
    int p;
    scanf("%d",&p);
    for (int i = 0; i < p; i++){
        char ca[30],cm[25];
        scanf("%s %s",ca,cm);
        for (int j = 0; j < m; j++){
            if(!strcmp(d[j].codig,cm)){
                for (int k = 0; k < n; k++){
                    if(!strcmp(a[k].codig,ca)){
                        strcpy(d[j].matric[d[j].nma],a[k].nome);
                        d[j].nma++;
                        break;
                    }
                }
                break;
            }
        }
        
    }
    printf("%d\n%d\n%.02f\n%.02f\n",qtM,qtF,medI,medIE);
    for (int i = 0; i < m; i++){
        for (int j = i+1; j < m; j++){
            if(strcmp(d[i].nome,d[j].nome)>0){
            int temp=d[i].ordem;
            d[i].ordem=d[j].ordem;
            d[j].ordem=temp;
            }
        }
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < d[i].nma; j++){
            for (int k = j+1; k < d[i].nma; k++){
                if(strcmp(d[i].matric[j],d[i].matric[k])>0){
                    char temp[500];
                    strcpy(temp,d[i].matric[j]);
                    strcpy(d[i].matric[j],d[i].matric[k]);
                    strcpy(d[i].matric[k],temp);
                }
            }
            
        }
    }
    for (int i = 0; i < m; i++){
        int j;
        for (j = 0; j < m; j++){
            if(d[j].ordem==i) break;
        }
        printf("%s\n",d[j].nome);
        printf("%d\n",d[j].nma);
        for (int k = 0; k < d[j].nma; k++){
            printf("%s\n",d[j].matric[k]);
        }
    }
    return 0;
}