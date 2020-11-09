#include <stdio.h>
#include <string.h>
char Jounins[10000][10000], Pericia[10000][10000];
int Entradas, j, Sapo = 0; Cobra = 0; Lesma = 0; Macaco = 0; Cao = 0;
int main() {
    scanf("%d", &Entradas);
    for(int i = 0; i < Entradas; i++){
        scanf("%[^\n]", Jounins[i]);
        scanf("%[^\n]", Pericia[i]);
        printf("%s %s\n");
    }
    for(int i = 0; i < Entradas; i++){
        if(strcmp(Pericia[i], "Coragem") || strcmp(Pericia[i], "Determinação") || strcmp(Pericia[i], "Convicção")){
            if(Sapo == 0){
                printf("Sapos:\n- %s", Jounins[i]);
                Sapo = 1;
            }
            if(Sapo == 1){
                printf("\n- %s", Jounins[i]);
            }
            j++;
        }
    }
    for(int i = 0; i < Entradas; i++){
        if(strcmp(Pericia[i], "Ambição") || strcmp(Pericia[i], "Astúcia") || strcmp(Pericia[i], "Expertise")){
            if(Cobra == 0){
                printf("Cobras:\n- %s", Jounins[i]);
                Cobra = 1;
            }
            if(Cobra == 1){
                printf("\n- %s", Jounins[i]);
            }
            j++;
        }
    }
    for(int i = 0; i < Entradas; i++){
        if(strcmp(Pericia[i], "Análise") || strcmp(Pericia[i], "Suporte") || strcmp(Pericia[i], "Técnica")){
            if(Lesma == 0){
                printf("Lesmas:\n- %s", Jounins[i]);
                Lesma = 1;
            }
            if(Lesma == 1){
                printf("\n- %s", Jounins[i]);
            }
            j++;
        }
    }
    for(int i = 0; i < Entradas; i++){
        if(strcmp(Pericia[i], "Agilidade") || strcmp(Pericia[i], "Inteligência") || strcmp(Pericia[i], "Destreza")){
            if(Macaco == 0){
                printf("Macacos:\n- %s", Jounins[i]);
                Macaco = 1;
            }
            if(Macaco == 1){
                printf("\n- %s", Jounins[i]);
            }
            j++;
        }
    }
    for(int i = 0; i < Entradas; i++){
        if(strcmp(Pericia[i], "Experiência") || strcmp(Pericia[i], "Perspicácia") || strcmp(Pericia[i], "Perícia")){
            if(Cao == 0){
                printf("Cães:\n- %s", Jounins[i]);
                Cao = 1;
            }
            else if(Cao == 1){
                printf("\n- %s", Jounins[i]);
            }
            j++;
        }
    }
    if(j == 0){
        printf("Nao havera Jounins forte esse ano");
    }
    return 0;
}