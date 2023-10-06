#include <stdio.h>

int main(){
    	FILE *fp;
    	char s;
    	fp=fopen("/home/davi/Documentos/teste.txt","r");
    	if(fp==NULL)
    	{
    		printf("\nCAN NOT OPEN FILE");
    		exit(1);
    	}
    	do
        {
    		s=getc(fp);
    		printf("%c",s);
    	}
    	while(s!=EOF);
    	fclose(fp);
}