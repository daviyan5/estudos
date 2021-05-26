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

struct Estrada{
    int u, v, cost;
    bool operator < (Estrada b) {
        return cost < b.cost;
    }
};
int ans,num;
void Kruskal(int n,int m,vector<Estrada> &v) {
    sort(v.begin(), v.end());
    build(n);
    ans = INT_MIN;
    num=0;
    for (int i = 0; i < m; i++) {
        if (find(v[i].u) != find(v[i].v)) {
            join(v[i].u, v[i].v);
            ans = max(v[i].cost,ans);
            num++;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    while(true){
        int n,m; cin >> n >> m;
        if(n==0 && m == 0) break;
        if(m==0){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        vector<Estrada> v(m);
        forc(i,m){
            cin >> v[i].u >> v[i].v >> v[i].cost;
        }
        Kruskal(n,m,v);
        if(num!=n-1) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }
    return 0;
}