#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define x first
#define y second
#define all(cc) (cc).begin(),(cc).end()
typedef pair<long long,int> ii;
typedef long long LL;
typedef long double LD;
const LL inf = 922337203685477580;
const int MX=1e6 + 20;
int biton(int N, int pos) {return N = N | (1 << pos);}
int bitoff(int N, int pos) {return N = N & ~(1 << pos);}
//resposta = minimo entre a distancia de (1,1) ate (n-1,m-1) e a distancia de (1,1) portal mais proximo + custo + distancia de (n-1,m-1) ate o portal mais proximo
//calcular distancias de (1,1)
//calcular distancias de (n-1,m-1)
int n,m,w;
void djikstra(vector<vector<int>> &v,vector<LL> &dist,int source){
    dist[source] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0, source);
    while (!pq.empty()){
        LL d = pq.top().first, u = pq.top().second;
        //cout << "d: " << d << " u: " << u <<" dist de u: " << dist[u] << endl;
        pq.pop();
        if (d > dist[u]) continue;

        int i = u / m; int j = u % m;

        if(i > 0 and v[i-1][j]!=-1){
            int v = (i-1)*m + j;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.emplace(dist[v],v);
            }
        }
        if(i < n-1 and v[i+1][j]!=-1){
            int v = (i+1)*m + j;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.emplace(dist[v],v);
            }
        }
        if(j > 0 and v[i][j-1]!=-1){
            int v = (i)*m + j-1;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.emplace(dist[v],v);
            }
        }
        if(j < m-1 and v[i][j+1]!=-1){
            int v = (i)*m + j+1;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.emplace(dist[v],v);
            }
        }
    }
    //cout << "Fim djikstra" << endl;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n >> m >> w;
    vector<vector<int>> v(n);
    vector<int> portal;
    vector<LL> distO(n*m+1,inf),distC(n*m+1,inf);
    forc(i,n){
        forc(j,m){
            int a; cin >> a;
            v[i].push_back(a);
            if(a > 0){
                portal.push_back(i*m + j);
            }
        }
    }
    djikstra(v,distO,0);
    djikstra(v,distC,n*m - 1);
    LL ans = distO[n*m-1];
    bool temC = !(ans == inf);
    //cout << ans << endl;
    LL closeO = inf; LL closeC = inf;
    for(auto u:portal){
        int i = u/m; int j = u%m;
        if(distO[u]!=inf) closeO = min(closeO,distO[u] + v[i][j]);
        if(distC[u]!=inf) closeC = min(closeC,distC[u] + v[i][j]);
        //cout << u << " i: " << i << " j: " << j << endl;
        //cout <<"PortalO: " << closeO << " " << distO[u] << " " << v[i][j] << endl;
        //cout <<"PortalC: " << closeC << " " << distC[u] << " " << v[i][j] << endl;
        
    }
    bool temP = !(closeO == inf or closeC == inf);
    ans = min(ans,closeO + closeC);
    if(temC or temP) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}