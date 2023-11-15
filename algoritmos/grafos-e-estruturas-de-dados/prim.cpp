#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;

const int inf = 0x3f3f3f3f;

void Prim(int n, int m){
    vector<vector<ii>> adjList(n);

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }

    vector<int> T(n, -1);
    vector<int> W(n, inf);

    int source = 0;
    W[source] = 0;

    priority_queue<ii,vector<ii>,greater<ii>> H;
    H.push(make_pair(W[source], source));

    int c = 0;

    for(int k = 0; k < n; k++){
        auto aux = H.top();
        H.pop();

        int u = aux.second;
        int x = aux.first;
        c += x;

        for(auto gr : adjList[u]){
            int v = gr.first;
            int w = gr.second;

            if(w < W[v]){
                W[v] = w;
                T[v] = u;
                H.push(make_pair(W[v], v));
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
        int n, m;
        cin >> n >> m;
        Prim(n, m);
    }

    return 0;
}
