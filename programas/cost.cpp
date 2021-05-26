#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX = 1e6 + 10;

vector<int> dist;
vector<vector<ii>> adj;

int djikstra(int source,int n){
    dist.resize(n);
    int ans=0;
    for(int i = 0; i < n; i++) dist[i] = inf;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0, source);
    while (!pq.empty()){
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d > dist[u]){
            ans-=dist[u];
            continue;
        }
        ans-=d;
        for(auto e : adj[u]){
            int v = e.first, w = e.second;
            if (dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.emplace(dist[v],v);
            }
        }
    }
    return ans;

}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n,m; cin >> n >> m;
    LL total=0;
    adj.resize(n);
    forc(i,m){
        int a,b,w; cin >> a >> b >> w;
        w=-w;
        a--; b--;
        total-=w;
        adj[a].pb(mp(b,w));
        adj[b].pb(mp(a,w));
    }
    LL ans=0;
    for(int i=0;i<n;i++){
        ans += total-djikstra(i,n);
    }
    LL mod=1e9;
    cout << ans%mod << endl;
    return 0;
}