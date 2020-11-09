#include <stdio.h>
int main()
{   int contador = 0;
    char c;
    do
    {
        contador += 1;
        printf("Digite 0 para sair do looping\n");
        printf("%i quantidade de vezes.\n", contador);
        c = getchar();
    }
    //while( false  );
    while( c != '0' );




    return 0;
}