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
vector<ii> cond; vector<ii> op;
vector<bool> vis;
int k; int ans = INT_MIN;

void backtrack(int pos){
    if(pos == k){
        int aux=0;
        for(auto u:cond){
            if(vis[u.x] && vis[u.y]) aux++;
        }
        ans = max(ans,aux);
    }
    else{
        int c=op[pos].x;
        int d=op[pos].y;
        if(vis[c] && vis[d]){
            backtrack(pos+1);
        }
        else if(vis[c]){
            vis[d]=true;
            backtrack(pos+1);
            vis[d]=false;
        }
        else if(vis[d]){
            vis[c]=true;
            backtrack(pos+1);
            vis[c]=false;
        }
        else{
            vis[c]=true;
            backtrack(pos+1);
            vis[c]=false; vis[d]=true;
            backtrack(pos+1);
            vis[d]=false;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n,m; cin >> n >> m;
    vis.resize(n);
    vis.assign(n,false);
    forc(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        cond.pb(mp(a,b));
    }
    cin >> k;
    forc(i,k){
        int a,b; cin >> a >> b;
        a--; b--;
        op.pb(mp(a,b));
    }
    backtrack(0);
    cout << ans << endl;
    return 0;
}