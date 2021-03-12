#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graf;
vector<bool> cores;
vector<bool> vis;

bool colore(int v,bool cor){
    if(vis[v]) return true;
    vis[v]=true;
    cores[v]=cor;
    for(auto u: graf[v]){
        if(!colore(u,!cor)) return false;
        if(cores[u]==cores[v]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n;
    int l;
    while(true){
        cin >> n;
        if(n==0) break;
        graf.clear(); graf.resize(n);
        cores.clear(); cores.resize(n);
        vis.clear(); vis.resize(n);
        cin >> l;
        for (int i = 0; i < l; i++){
            int a,b;
            cin >> a >> b;
            graf[a].push_back(b); graf[b].push_back(a);

            vis[a]=false; vis[b]=false;
        }
        if(colore(0,false)) cout << "BICOLORABLE" << endl;
        else cout << "NOT BICOLORABLE" << endl;
    }

}