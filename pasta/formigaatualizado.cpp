#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int xo,yo,vez=0;
    cout << "Digite o tamanho do espaço (x,y): ";
    while(1){
        cin >> xo >> yo;
        if(xo < 0 or yo < 0){
            cout << "Tamanho inadequado, tente novamente: ";
            continue;
        }
        else break;
    }
    char esp[yo][xo] = {'o'};
    for (int i = 0; i < yo; i++){
        for (int j = 0; j < xo; j++){
            esp[i][j]='o';
        }
    }
    pair<int,int> pos;
    short esq,dir;
    cout << "Digite a posição inicial da formiga: ";
    while(1){
        cin >> pos.first >> pos.second;
        if (pos.first > xo or pos.second > yo or pos.first<0 or pos.second<0){
            cout << "Posições inadequadas, tente novamente: ";
            continue;
        }
        else {
            while(1){
                cout << "Digite a orientação inicial da formiga (norte = 1, leste = 2, sul = 3, oeste = 4): ";
                cin >> dir;
                esq=dir;
                if(dir < 0 or dir > 4){
                    cout << "Posições inadequadas, tente novamente: ";
                    continue;
                }
                else break;
            }
            break;
        }
    }

    while(1){
        
        if (pos.first > yo) pos.first=0;
        else if (pos.first < 0) pos.first=yo;
        if (pos.second > xo) pos.second=0;
        else if (pos.second < 0) pos.second=xo;
        for (int i = 0; i < yo; i++){
            for (int j = 0; j < xo; j++){
                cout << esp[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        if(vez==0){
            cout << "Terminar? (s ou n) ";
            char respo;
            cin >> respo;
            if(respo=='s'){
                return 0;
            }
            else{
                aqui:
                cout << "Quantas vezes?: ";
                cin >> vez;
                if(vez<=0){
                    cout << "Invalido: ";
                    goto aqui;
                }
                continue;
            }
        }
        vez--;
    }




}