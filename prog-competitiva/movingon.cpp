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
int risco[210];
int dist[210][210][210];
vector<int> v;

bool ris(int a,int b){
    return risco[a]<risco[b];
}
void floyd(int n){
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[k][i][j] = min(dist[k-1][i][j], dist[k-1][i][v[k]] + dist[k-1][v[k]][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    int cas=1;
    while(t--){
        int n,q; cin >> n >> q;
        v.resize(n+1);
        for(int i=1;i<=n;i++){
            cin >> risco[i];
            v[i]=i;
        }
        sort(v.begin()+1,v.end(),ris);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> dist[0][i][j];
            }
        }
        floyd(n);
        cout << "Case #" << cas++ << ":" << endl;
        while (q--){
            int a,b,w; cin >> a >> b >> w;
            int ans=0;
            for(int i=1;i<=n;i++){
                if(risco[v[i]]<=w){
                    ans=i;
                }
            }
            cout << dist[ans][a][b] << endl;
        }
    }
    return 0;
}