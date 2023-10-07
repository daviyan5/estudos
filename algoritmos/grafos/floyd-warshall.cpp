#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX = 1e5 + 10;

vector<vector<int>> dist;

void floyd(int n, int m){
    dist.clear();
    dist.resize(n);
    for(int i = 0; i < n; i++){
        dist[i].resize(n);
        for(int j = 0; j < n; j++) {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = inf;
        }
    }
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "Distancia de " << i << " ate " << j << " é: " << dist[i][j] << endl;
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        floyd(n, m);
    }

    return 0;
}
