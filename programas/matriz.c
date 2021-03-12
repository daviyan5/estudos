#include <stdio.h>
#include <string.h>

int **leMatriz(int **m){
    for (int i = 1; i <= 9; i++){
        m=(int**)realloc(m,i*sizeof(int*)); //aloca as linhas
        for (int j = 1; j <= 9; j++){
            m[i-1]= (int*)realloc(m[i-1],j*sizeof(int)); //aloca as colunas
            scanf("%d",&m[i-1][j-1]);
        }
    }
    return m;
}
int verificaMatrizGlobal(int **m){
    int linha[10][10],coluna[10][10]; //matrizes pra conferir cada uma das nove linhas e colunas
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){ //agrega um valor inicial pra cada matriz no indice, ja que cada linha/coluna precisa conter cada um dos 9 digitos
            linha[i][j]=1;
            coluna[i][j]=1;
        }
    }
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            int a=m[i][j]; 
            linha[i][a]--; //é o equivalente a dizer "na linha i, o elemento a já apareceu"
            coluna[j][a]--;// o mesmo de cima
            if(linha[i][a]<0 || coluna[j][a]<0) { //se for negativo, significa que apareceu duas vezes
                free(m);
                return 0; //retorna que o sudoku está errado globalmente
            }
            
        }
    }
    return 1; //retorna que está correto globalmente
}
int verificaMatrizInterna(int **m){
    int reg[10][10]; //parecido com o global, porem esta matriz é para cada uma das 9 regioes
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            reg[i][j]=1; //equivalente ao pensamento do global
        }
    }
    for (int i = 0; i < 9; i++){
        int b,c; //b e c servem para variar as posiçoes de analise na matriz global, para que se verifique apenas na dada região
        if(i<3) b=0; //Essa e as linhas subsequentes dizem respeito apenas a "qual a coordenada na qual deve-se começar a analisar as regiões"
        else if(i<6) b=3;
        else if(i<9) b=6;
        if(i%3==0) c=0;
        else if(i%3==1) c=3;
        else if(i%3==2) c=6;
        for (int h = b; h < b+3; h++){ //O intervalo no for muda a cada iteração do for de "i". Assim variando as regioes
            for(int k= c; k < c+3; k++){
                int a=m[h][k];
                reg[i][a]--; //equivalente ao global
                if(reg[i][a]<0) {
                free(m);
                return 0;
                }
            }
        } 
    }
    return 1;
}


int main (){
   int **matriz=NULL; //declaração de matriz como ponteiro
   matriz=leMatriz(matriz); //chama a função de leitura, e retorna o ponteiro
   if(verificaMatrizGlobal(matriz)==1){ //caso passe na verificação global
       if(verificaMatrizInterna(matriz)==1){  //caso passe na verificação interna
           printf("YES\n");
       }
       else printf("NO\nINTERNA\n"); //caso não passe na verificação interna
   }
   else printf("NO\nGLOBAL\n"); //caso não passe na verificação global
   free(matriz);
   return 0;
}