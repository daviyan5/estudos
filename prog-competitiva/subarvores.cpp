#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<long long int>> graf;
vector<bool> vis;
long long int auxCont;
void dfs(int v,int exit){
    if(v==exit){
        auxCont++;
        return;
    }
    vis[v]=true;
    for (auto u: graf[v]){
        if(!vis[u]) dfs(u,exit);
    }
    vis[v]=false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        long long int n; cin >> n;
        graf.clear();
        graf.resize(n+1);
        vis.resize(n+1);
        for (long long int i = 0; i < n; i++){
            long long int a,b;
            cin >> a >> b;
            graf[a].push_back(b);
            graf[b].push_back(a);
        }
        long long int conta=0;
        for (long long int i = 1; i <= n; i++){
            for (long long int v = i+1; v <= n; v++){
                auxCont=0;
                fill(vis.begin(),vis.end(),false);
                dfs(i,v);
                conta+=auxCont;
            }
        }
        cout << conta << endl;
    }
    
}