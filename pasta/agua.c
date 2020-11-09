#include <stdio.h>

int main()
{int pagamento;
scanf("%d",&pagamento);
if (pagamento<0) printf("Digite o consumo de agua em m3:\nNumeros negativos nao sao aceitos.");
else if (pagamento<=10) printf("Digite o consumo de agua em m3:\nO valor a ser pago e de R$ 7.");
else if (pagamento>10 && pagamento<=30) { pagamento = (pagamento-10)*1+7;
    printf("Digite o consumo de agua em m3:\nO valor a ser pago e de R$ %d.",pagamento);}
else if (pagamento>30 && pagamento<=100){pagamento = 27+(pagamento-30)*2;
    printf("Digite o consumo de agua em m3:\nO valor a ser pago e de R$ %d.",pagamento);}
else if (pagamento>100){pagamento = 167+(pagamento-100)*5;
    printf("Digite o consumo de agua em m3:\nO valor a ser pago e de R$ %d.",pagamento);}
    return 0;

}