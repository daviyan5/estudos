#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;
#include <iostream>
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<set<int>> graf;
map<int,vector<int>> con;
vector<bool> vis;

void colore(int v,int cor){
    if(vis[v]) return;
    vis[v]=true;
    con[cor].push_back(v);
    for(auto u: graf[v]){
        colore(u,1-cor);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    vis.resize(n+1);
    graf.resize(n+1);
    forc(i,n-1){
        int a,b; cin >> a >> b;
        graf[a].insert(b);
        graf[b].insert(a);
    }
    colore(1,0);
    long long int ans=0;
    for(auto u: con[0]){
        ans+=con[1].size()-graf[u].size();
    }
    cout << ans << endl;
    return 0;
}