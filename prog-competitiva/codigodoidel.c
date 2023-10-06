#include<stdio.h>
int main () {
	float pilula1total,pilula1m,pilula2total,pilula2m,comppilula,pilula3total,pilula3m;
	int pilula1h,pilula2h,pilula3h;
	printf("Ze tomou a primeira pilula que horas?(descreva a hora em uma variavel e os minutos em outra)\n");
	scanf("%d %f",&pilula1h,&pilula1m);
	pilula1total=pilula1h*60+pilula1m;
	comppilula=pilula1total+192;
	if(pilula1total<719){
		printf("Ze tomou a segunda pilula que horas?(descreva a hora em uma variavel e os minutos em outra)\n");
		scanf("%d %f",&pilula2h,&pilula2m);
		pilula2total=(pilula2h*60)+pilula2m;
		if(pilula2total==comppilula){
			printf("Ze tomou a terceira pilula que horas?(descreva a hora em uma variavel e os minutos em outra)\n");
			scanf("%d %f",&pilula3h,&pilula3m);
			comppilula=comppilula+1380;
			comppilula=comppilula-1440;
			pilula3total=pilula3h*60+pilula3m;
				if(pilula3total==comppilula)
			printf("Ze tomou as tres pilulas no horario certo\n");
			else 
			printf("Ze nao tomou a terceira pilula no horario certo\n");
		}
		else printf("Nao tomou a segunda pilula no horario certo\n");
		
				} else 
	printf("Nao tomou a primeira pilula no horario certo\n");
	return 0;
}	