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
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX=1e6 + 20;
int biton(int N, int pos) {return N = N | (1 << pos);}
int bitoff(int N, int pos) {return N = N & ~(1 << pos);}

int n,m;
char matriz[26][26];
int djikstra(int source,int des){
    int dist[n*m];
    forc(i,n*m){
        dist[i] = inf;
    }
    dist[source] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0, source);
    while (!pq.empty()){
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        //cout << u << endl;
        int i = u/m; int j = u%m;
        if(i>0 && matriz[i-1][j]!='X'){ // cima
            int pos = (i-1)*m + j;
            if(matriz[i-1][j]=='D'){
                if(dist[u] < dist[pos]){
                    dist[pos] = dist[u];
                    pq.emplace(dist[pos],pos);
                }
            }
            else{
                int w = matriz[i-1][j] - '0';
                if(dist[u] + w < dist[pos]){
                    dist[pos] = dist[u] + w;
                    pq.emplace(dist[pos],pos);
                }
            }
        }
        if(i<n-1 && matriz[i+1][j]!='X'){ // baixo
            int pos = (i+1)*m + j;
            if(matriz[i+1][j]=='D'){
                if(dist[u] < dist[pos]){
                    dist[pos] = dist[u];
                    pq.emplace(dist[pos],pos);
                }
            }
            else{
                int w = matriz[i+1][j] - '0';
                if(dist[u] + w < dist[pos]){
                    dist[pos] = dist[u] + w;
                    pq.emplace(dist[pos],pos);
                }
            }
        }
        if(j>0 && matriz[i][j-1]!='X'){ // esq
            int pos = (i)*m + j-1;
            if(matriz[i][j-1]=='D'){
                if(dist[u] < dist[pos]){
                    dist[pos] = dist[u];
                    pq.emplace(dist[pos],pos);
                }
            }
            else{
                int w = matriz[i][j-1] - '0';
                if(dist[u] + w < dist[pos]){
                    dist[pos] = dist[u] + w;
                    pq.emplace(dist[pos],pos);
                }
            }
        }
        if(j<m-1 && matriz[i][j+1]!='X'){ //dir
            int pos = (i)*m + j+1;
            if(matriz[i][j+1]=='D'){
                if(dist[u] < dist[pos]){
                    dist[pos] = dist[u];
                    pq.emplace(dist[pos],pos);
                }
            }
            else{
                int w = matriz[i][j+1] - '0';
                if(dist[u] + w < dist[pos]){
                    dist[pos] = dist[u] + w;
                    pq.emplace(dist[pos],pos);
                }
            }
        }
    }
    return dist[des];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    while(cin >> m >> n){
        if(n==0 && m==0) break;
        int com,fim;
        forc(i,n){
            forc(j,m){
                cin >> matriz[i][j];
                if(matriz[i][j] == 'S'){
                    com = i*m + j;
                }
                else if(matriz[i][j] == 'D'){
                    fim = i*m + j;
                }
            }
        }
        int ans = djikstra(com,fim);
        cout << ans << endl;
    }
    return 0;
}