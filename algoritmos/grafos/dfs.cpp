#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;

void dfs(vector<vector<int>>& graf,vector<bool>& vis,int pos,int e){
    if(pos==e) return;
    vis[pos]=true;
    for(auto u: graf[pos]){
        if(!vis[pos]) dfs(graf,vis,u,e);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int v,e;
    cin >> v >> e;
    vector<vector<int>> graf(v);
    vector<bool> vis(v,false);
    for(int i=0;i<e;i++){
        int a, b; cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    int end; cin >> end;
    dfs(graf,vis,0,end);
    return 0;
}