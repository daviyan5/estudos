#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main(){
    int n,m;
    set <int> fila;
    cin >> n;
    long long int ele[100001],ele1[n];
    for (int i = 0; i < n; i++){
        int ind;
        cin >> ind;
        ele[ind]=i;
        ele1[i]=ind;
        fila.insert(i);
    }
    cin >> m;
    for (int i = 0; i < m; i++){
        int s;
        cin >> s;
        fila.erase(ele[s]);
    }
    bool prim=true;
    for(auto i=fila.begin();i!=fila.end();++i){
        intptr_t a=*i;
        if(prim) cout << ele1[a];
        else cout << ' '<<ele1[a];
        prim=false;
    }
}