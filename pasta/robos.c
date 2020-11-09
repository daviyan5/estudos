#include <stdio.h>
#include <math.h>

int main(){
    char tim[8],semif[4],fin[2];
    int qrt1[4],qrt2[4];
    for (int i = 0; i < 8; i++){
        scanf("%c\n",&tim[i]);
    }
    for (int i = 0; i < 4; i++){
        scanf("%d %d\n",&qrt1[i],&qrt2[i]);
        printf("Quartas de final %d: %c x %c\n",i+1,tim[qrt1[i]],tim[qrt2[i]]);
    }
    for (int i = 0; i < 4; i++){
        scanf("%c\n",&semif[i]);
        if(semif[i]=='A') semif[i]=tim[qrt1[i]];
        else semif[i]=tim[qrt2[i]];
        if(i==1) printf("Semifinal 1: %c x %c\n",semif[0],semif[1]);
        if(i==3) printf("Semifinal 2: %c x %c\n",semif[2],semif[3]);
    }
    scanf("%c\n",&fin[0]);
    scanf("%c\n",&fin[1]);
    if(fin[0]=='X') fin[0]=semif[0];
    else fin[0]=semif[1];
    if(fin[1]=='X') fin[1]=semif[2];
    else fin[1]=semif[3];
    printf("Final: %c x %c\n",fin[0],fin[1]);
    char ven;
    scanf("%c\n",&ven);
    if(ven=='#') printf("O vencedor da competi��o de futebol de rob�s foi %c!\n",fin[0]);
    else printf("O vencedor da competi��o de futebol de rob�s foi %c!\n",fin[1]);
    return 0;
    
    

}