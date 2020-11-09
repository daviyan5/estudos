#include <iostream>
#include <math.h>
using namespace std;

int gerador(int x){
    return x^(x)%5;
}
int main(){
    short m,n,vez=0;
    cout << "Digite o tamanho da chuva (x,y): ";
    cin >> m >>n;
    cout << endl;
    char el,chuva[m+1][n+1],chuva2[m+1][n+1];
    cout << "Digite a chave de geração aleatória: ";
    int chave,chave2;
    cin >> chave;
    cout << endl;
    chave2=chave%7;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(gerador(chave)%3!=1) chuva[i][j]='.';
            else chuva[i][j]='#';
            chave=chave+chave2;
            chave2=chave%7;
        }
    }
    chuva[0][chave%m]='o';
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (chuva[i][j]=='.'){
                if(chuva[i-1][j]=='o') chuva[i][j]='o';
                if(chuva[i][j-1]=='o' and chuva[i+1][j-1]=='#') chuva[i][j]='o';
                if(chuva[i][j+1]=='o' and chuva[i+1][j+1]=='#') chuva[i][j]='o';
                
            }
        }
        for (int j=n-1; 0<=j;j--){
            if (chuva[i][j]=='.'){
                if(chuva[i-1][j]=='o') chuva[i][j]='o';
                if(chuva[i][j+1]=='o' and chuva[i+1][j+1]=='#') chuva[i][j]='o';
                
            }

        }
    }
    bool foi=true;
    comeco:
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(foi){
                chuva2[i][j]=chuva[i][j];
                if(chuva[i][j]=='o' and gerador(chave)%3!=1) chuva[i][j]='.';
                cout << chuva[i][j] << " ";
                chave=chave+chave2;
                chave2=chave%7;
            }
            else{
                chuva[i][j]=chuva2[i][j];
                if(chuva2[i][j]=='o' and gerador(chave)%3!=1) chuva2[i][j]='.';
                cout << chuva2[i][j] << " ";
                chave=chave+chave2;
                chave2=chave%7;
            }
        }
        cout << endl;
    }
    if(vez==0){
        cout << "Novamente ? (s ou n) ";
        char p;
        cin >> p;
        if (p=='s'){
            aqui:
            cout << "Quantas vezes?: ";
            cin >> vez;
            if(vez<0){
                cout << "Inválido";
                goto aqui;
            }
            if(foi) foi=false;
            else foi=true;
            goto comeco;
        }
        else return 0;
    }
    else{
        vez--;
        goto comeco;
    }
    }