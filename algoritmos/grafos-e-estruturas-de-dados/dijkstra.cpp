#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX = 1e5 + 10;

vector<int> dist;
vector<vector<ii>> adj;

void djikstra(int source, int n){

    for(int i = 0; i < n; i++) dist[i] = inf;
    dist[source] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0, source);

    while (!pq.empty()){
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;

        for(auto e : adj[u]){
            int v = e.first, w = e.second;
            if (dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.emplace(dist[v],v);
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        adj.clear();
        dist.clear();
        int n,m;
        cin >> n >> m;
        adj.resize(n);
        dist.resize(n);

        for(int i = 0; i < m; i++){
            int a, b, p;
            cin >> a >> b >> p;
            adj[a].push_back(make_pair(b, p));
            adj[b].push_back(make_pair(a, p));
        }

        while(true){
            dist.clear();
            cout << "Digite de onde começa" << endl;
            int st;
            cin >> st;

            if(st < 0)
                break;

            djikstra(st, n);

            for(int i = 0; i < n; i++){
                cout << "Distancia de " << st << " para " << i << " é: " << dist[i] << endl;
            }

            cout << endl;
        }
    }

    return 0;
}
