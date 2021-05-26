#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define pb push_back
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;

void Prim(int n,int m){
    vector<vector<ii>> adjList(n);
    forc(i,m){
        int u,v,w; cin >> u >> v >> w;
        adjList[u].pb(mp(v,w));
        adjList[v].pb(mp(u,w));
    }
    vector<int> T(n,-1);
    vector<int> W(n,inf);
    int source = 0;
    W[source] = 0;
    priority_queue<ii,vector<ii>,greater<ii>> H;
    H.push({W[source],source});
    int c = 0;
    for(int k=0;k<n;k++){
        auto aux = H.top(); H.pop();
        int u = aux.second;
        int x = aux.first;
        c += x;
        for(auto gr:adjList[u]){
            int v = gr.first;
            int w = gr.second;
            if(w < W[v]){
                W[v] = w;
                T[v] = u;
                H.push({W[v],v});
            }
        }
    }
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        Prim(n,m);
    }
    return 0;
}