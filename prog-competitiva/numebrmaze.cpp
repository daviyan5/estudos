#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define endl '\n'
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX=1e6 + 20;
int custo[MX];
int dist[MX];
int m,n;

int djikstra(){
    dist[0] = custo[0];
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(dist[0],0);
    while (!pq.empty()){
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        int i=u/m; int j=u%m;
        vector<ii> graf;
        if(u - m >= 0) { //cima
            graf.push_back(mp(custo[u-m],u-m));
        }
        if(u + m < m*n){ //baixo
            graf.push_back(mp(custo[u+m],u+m));
        }
        if(u - 1 >= i*m){ //esq
            graf.push_back(mp(custo[u-1],u-1));
        }
        if(u + 1 < (i+1)*m){ //dir
            graf.push_back(mp(custo[u+1],u+1));
        }
        for(auto e : graf){
            int v = e.second, w = e.first;
            if (dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.emplace(dist[v],v);
            }
        }
    }
    return dist[m*n-1];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
       cin >> n >> m;
       if(n==0 && m==0) continue;
       forc(i,n){
           forc(j,m){
               cin >> custo[i*m+j];
               dist[i*m+j]=inf;
           }
       }
       cout << djikstra() << endl;
    }
    return 0;
}