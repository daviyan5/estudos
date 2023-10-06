#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define endl '\n'
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;

const int MX = 1e6 + 10;
int sz[MX], root[MX];

void build(int n){
    for(int i=0;i<n;i++){
        sz[i]=1;
        root[i]=i;
    }
}
int find(int a){
    if(a == root[a]) return a;
    return root[a] = find(root[a]);
}
void join(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(sz[a] < sz[b])
            root[b] = a;  
        else root[a] = b;
        sz[a] += sz[b];
        sz[b] = sz[a];
    }
}
struct Edge{
    int u, v, cost;
    bool operator < (Edge b) {
        return cost < b.cost;
    }
};
vector<Edge> mst;

void Kruskal(int m) {
    vector<Edge> grafo(m);
    for (int i = 0; i < m; i++) {
        cin >> grafo[i].u >> grafo[i].v >> grafo[i].cost;
    }
    sort(grafo.begin(), grafo.end());
    long long total = 0;
    build(m);
    for (int i = 0; i < m; i++) {
        if (find(grafo[i].u) != find(grafo[i].v)) {
            join(grafo[i].u, grafo[i].v);
            mst.push_back(grafo[i]);
            total += grafo[i].cost;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        Kruskal(n); 
    }
    return 0;
}