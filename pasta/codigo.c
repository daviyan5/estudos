#include <stdio.h>
main() {
int a,b,f,i,r,min,max,z;
printf("Digite dois valores para ser calculado os numeros primos dentro do intervalo:\n");
scanf("%d %d",&a,&b);
if (a<b){
    min=a; max=b;
    }
else {
    min=b; max=a;
    }
i=2; z=0; f=0;
printf("\nValores entre %d e %d:\n",min,max);
while(min<=max) {
    while(min>=i) {
        r=min%i;
    if (r==0)
        z=z+1; i=i+1;
    }
    if (z==1){
        f=f+1;  if (f==1)
                    printf("(%d",min);
            else if (f>1)
                    printf(", %d",min);
    }
    min=min+1; i=2; z=0;
    }
if (f>0)
    printf(")\n\n");
else
    printf("Sem valores nesse intervalo.\n\n");
getchar();
}