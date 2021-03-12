#include <iostream>
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<int>> graf;
vector<bool> gender;
vector<bool> vis;

bool intera(int v,bool g){
    if(vis[v]) return true;
    vis[v]=true;
    gender[v]=g;
    for(auto u: graf[v]){
        if(!intera(u,!g)) return false;
        if(gender[u]==gender[v]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n;
    int l;
    int t; cin >> t;
    int aux=0;
    while(t--){
        cin >> n;
        graf.clear(); graf.resize(n+1);
        gender.clear(); gender.resize(n+1);
        vis.clear(); vis.resize(n+1);
        cin >> l;
        for (int i = 0; i < l; i++){
            int a,b;
            cin >> a >> b;
            graf[a].push_back(b); 
            graf[b].push_back(a);
            vis[a]=false; vis[b]=false;
        }
        printf("Scenario #%d:\n",aux+1);
        bool foi=true;
        for(int i=1;i<=n;i++){
            if(!intera(i,false)){
                foi=false;
                break;
            }
        }
        if(foi) printf("No suspicious bugs found!\n");
        else printf("Suspicious bugs found!\n");
        aux++;
    }

}