#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{int d;
scanf("%d",&d);
if (d<=10) printf("Arthur");
else if (d>10 && d<=30) printf("Luiz");
else if (d>30 && d<=100) printf("Pedro");
else if (d>100) printf("Nenhum");



return 0;
}