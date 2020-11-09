#include <stdio.h>
#include <math.h>

int main()
{int ax,ay,bx,by,cx,cy;
scanf("%d %d %d %d %d %d",&ax,&ay,&bx,&by,&cx,&cy);
if (((ax-bx)*(ax-bx)+(ay-by)*(ay-by))>=4 && ((ax-cx)*(ax-cx)+(ay-cy)*(ay-cy))>=4 && ((cx-bx)*(cx-bx)+(cy-by)*(cy-by))>=4) printf("POSICAO VALIDA");
else printf("POSICAO INVALIDA");
return 0;

}