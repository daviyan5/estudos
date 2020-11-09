#include <stdio.h>


int main(){
  int moedas,precoVerde,precoVermelho,precoRoxo,precoAmarelo,c1,c2,c3,c4;
  scanf("%d %d %d %d %d",&moedas,&precoVerde,&precoVermelho,&precoRoxo,&precoAmarelo);
  c1=(80/precoVerde);
  c2=(100/precoVermelho);
  c3=(120/precoRoxo);
  c4=(80/precoAmarelo);
  if (c1>=c2 && c1>=c3 && c1>=c4 && precoVerde<=moedas) printf("Verde");
  else if (c1>=c2 && c1>=c3 && c1>=c4 && precoVerde>moedas) printf("Acho que vou a pe :(");
  
  if (c2>c1 && c2>=c3 && c2>=c4 && precoVermelho<=moedas) printf("Vermelho");
  else if (c2>c1 && c2>=c3 && c2>=c4 && precoVermelho>moedas) printf("Acho que vou a pe :(");
  
  if (c3>c2 && c3>c1 && c3>=c4 && precoRoxo<=moedas) printf("Roxo");
  else if (c3>c2 && c3>c1 && c3>=c4 && precoRoxo>moedas) printf("Acho que vou a pe :(");
  
  if (c4>c2 && c4>c3 && c4>c1 && precoAmarelo<=moedas) printf("Amarelo");
  else if (c4>c2 && c4>c3 && c4>c1 && precoAmarelo>moedas) printf("Acho que vou a pe :(");
  
  return 0;
}
