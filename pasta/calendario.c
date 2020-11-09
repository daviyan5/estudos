#include <stdio.h>
#include <math.h>
int main()
{int dia,mes,ano;
scanf("%d %d %d",&dia,&mes,&ano);
if (mes>12 || dia>31 || dia<=0 || mes<=0 || ano<1900 || ano>2100) printf("invalida");
else if ((mes==2 || mes==4 || mes==6 || mes==9 || mes==11) && (dia==31)) printf ("invalida");
else if (ano%4!=0 && (mes==2 && dia==29)) printf ("invalida");
else if ((ano%100==0 && ano%400!=0) && (mes==2 && dia==29)) printf ("invalida");
else printf("valida");
return 0;
}