#include <stdio.h>
#include <math.h>


int main()
{float nota1,nota2,nota3;
scanf("%f %f %f",&nota1,&nota2,&nota3);
if (((nota1+nota2+nota3)/3)<5)
{
    printf("Informe a primeira nota:
Informe a segunda nota:
Informe a terceira nota:
Reprovado com media %f/n",(nota1+nota2+nota3)/3);
}
else if (5=<((nota1+nota2+nota3)/3)<7)
{
    printf("Informe a primeira nota:
Informe a segunda nota:
Informe a terceira nota:
Recuperacao com media %f/n",(nota1+nota2+nota3)/3);
}
else 
printf("Informe a primeira nota:
Informe a segunda nota:
Informe a terceira nota:
Aprovado com media %f/n",(nota1+nota2+nota3)/3);
}

return 0;
}