#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
  int hora,minutos;
  scanf("%d %d",&hora,&minutos);
  if (hora==0) printf("12\n%02d\nam\n",minutos);
  else if (hora<12) printf("%02d\n%02d\nam\n",hora,minutos);
  else if (hora>12) printf("%02d\n%02d\npm\n",(hora-12),minutos);
  else if (hora==12) printf("12\n%02d\npm\n",minutos);
}
