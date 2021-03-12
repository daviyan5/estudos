#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;
vector<vector<int>> graf;
map<int,LL> dis;
map<int,LL> qnt;
vector<bool> vis;
vector<LL> v;

LL dfs(int pos,int par){
    dis[pos]=dis[par]+1;
    qnt[pos]=1;
    vis[pos]=true;
    for(auto u:graf[pos]){
        if(!vis[u]){
            qnt[pos]+=dfs(u,pos);
        }
    }
    v.push_back(qnt[pos]-dis[pos]);
    return qnt[pos];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n,k; cin >> n >> k;
    graf.resize(n+1); vis.resize(n+1);
    fill(vis.begin(),vis.end(),false);
    forc(i,n-1){
        int a,b; cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs(1,0);
    sort(v.begin(),v.end(),greater<int>());
    LL ans=0;
    forc(i,n-k){
        ans+=v[i];
    }
    cout << ans << endl;
    return 0;
}