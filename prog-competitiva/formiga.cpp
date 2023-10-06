#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x,y,dir,esq;
    cout << "Digite o tamanho 'n' do espaço: " << endl;
    cin >> n;
    if (n <= 0){
        cout << "????????" <<endl;
        return 0;
    }
    char matriz[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
        matriz[i][j]='o';
        }
    }
    cout << "Digite a posição inicial (x,y) da formiga, entre '0' e 'n': " << endl;
    cin >> x >> y;
    if (x>n or y>n or x<0 or y<0){
        cout <<"Posicoes invalidas!" << endl;
        return 0;
    }
    cout << "Digite o estado inicial cardeal da formiga (norte=1,oeste=2,sul=3,leste=4): " << endl;
    cin >> esq;
    dir=esq;
    if (dir<1 or dir>4){
        cout << "Estado invalido!" << endl;
        return 0;
    }
    bool pare=false;
    queue<int> filaDir,filaEsq;
    for (int i = 0; i < 4; i++){
        filaDir.push(dir);
        if (dir==4) dir=1;
        else dir++;
        filaEsq.push(esq);
        if (esq==1) esq=4;
        else esq--;
    }
    int prox;
    while(!pare){
        if(matriz[y][x]=='o'){
            prox=filaDir.front();
            filaDir.pop();
            filaDir.push(prox);
            matriz[y][x]='*';
            switch (prox)
            {
                case 1:
                    y=y-1;
                break;
                case 2:
                    x=x-1;
                break;
                case 3:
                    y=y+1;
                break;
                case 4:
                    x=x+1;
                break;
            }
        }
        else{
            prox=filaEsq.front();
            filaEsq.pop();
            filaEsq.push(prox);
            matriz[y][x]='o';
            switch (prox)
            {
                case 1:
                    y=y-1;
                break;
                case 2:
                    x=x-1;
                break;
                case 3:
                    y=y+1;
                break;
                case 4:
                    x=x+1;
                break;
            }
        }
        if(x>n or x<0 or y>n or y<0){
            pare=true;
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << matriz[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        cout <<"x: " << x << " y: " << y <<" proxima direçao:"<< prox <<endl;
        char resp;
        cout << "Terminar ? (s,n)" << endl;
        cin >> resp;
        if (resp=='s') pare=true;
    }
    return 0;
}