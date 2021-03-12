#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> peso;
vector<int> valor;
vector<vector<int>> matriz;
int n,p;

int maxV(int w,int i){
    if(i<0) return 0;
    if(matriz[i][w]!=-1) return matriz[i][w];
    if(peso[i]>w){
        matriz[i][w]=maxV(w,i-1);
        return matriz[i][w];
    }
    else{
        matriz[i][w] = max(valor[i]+maxV(w-peso[i],i-1),maxV(w,i-1));
        return matriz[i][w];
    }
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n >> p;
    matriz.resize(n+1);
    peso.resize(n+1);
    valor.resize(n+1);
    for (int i = 0; i < n; i++){
        matriz[i].resize(p+1);
        fill(matriz[i].begin(),matriz[i].end(),-1);
        cin >> valor[i];
    }
    for (int i = 0; i < n; i++){
        cin >> peso[i];
    }
    cout << maxV(p,n-1) << endl;
    
}