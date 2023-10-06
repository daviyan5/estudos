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
const int MX=1e6 + 20;
bool func(ii &a,ii&b){
    return a.x < b.x;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n,m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<ii> a(n);
    vector<int> aux(n);
    forc(i,n){
        int p; cin >> p;
        a[i]=mp(p,i);
        aux[i] = p;
    }
    sort(a.begin(),a.end(),func);
    forc(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
    }
    vector<bool> vis(n+1,false);
    int ans = INT_MIN;
    for(auto u:a){
        int buy = u.x;
        cout << "buy "<<buy << endl;
        int sell = 0;
        for(auto t:adj[u.y]){
            if(vis[t]) continue;
            sell = max(sell,aux[t]);
            vis[t]=true;
        }
        cout << "sell "<< sell << endl;
        ans = max(ans,sell-buy);
    }
    reverse(a.begin(),a.end());
    vector<bool> ax(n,false);
    vis=ax;
    for(auto u:a){
        int sell = u.x;
        cout << "sell "<< sell << endl;
        int buy = u.x;
        for(auto t:adj[u.y]){
            if(vis[t]) continue;
            buy = min(buy,aux[t]);
            vis[t]=true;
        }
        cout << "buy "<< buy << endl;
        ans = max(ans,buy-sell);
    }
    cout << ans << endl;
    return 0;
}