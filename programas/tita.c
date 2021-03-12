#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int vt,vs,t,d1=5,d2=0;
	scanf("%d %d",&vt,&vs);
	for(int i=1;d2<=d1 && d1<50;i++){
	    d1=d1+vt;
	    d2=d2+vs;
	}
	if(d2>=50) d2=50;
	if(d1>=50) d1=50;
	if (d2>=d1){
	    printf("Capturamos ele, comandante!\n");
	    printf("Altura alcancada pelo tita: %d\n",d1);
	    printf("Altura alcancada pelo soldado: %d\n",d2);
	}
	else{
	    printf("Comandante, a operacao falhou!\n");
	    printf("Altura alcancada pelo soldado: %d\n",d2);
	}
	
	return 0;
}