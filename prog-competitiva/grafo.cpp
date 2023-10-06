#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

vector<vector<int>> g;
vector<bool> visit;
bool cor[200];

bool bicor(int u, bool color){
    if(visit[u]) return true;
    visit[u]=true;
    cor[u]= color;
    for(unsigned int i=0; i<=g[u].size();i++){
        int v= g[u][i];
        if(!bicor(v,!cor[u])) return false;
        if(cor[v]==cor[u]) return false;
    }
    return true;
}
bool grafo(int tamanh,int arestas){
    g.resize(tamanh);
    visit.resize(tamanh);
    int a,b;
    for(int i=0;i<arestas;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(bicor(g[0].front(),true)) return true;
    else return false;
}


int main(){
    for(int i=0;i<INFINITY;i=i){
        int tamanh,arestas;
        cin >> tamanh;
         if(tamanh==0) return 0;
        cin >> arestas;
        if (grafo(tamanh,arestas)) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }
}