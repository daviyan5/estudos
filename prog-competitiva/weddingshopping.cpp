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

vector<vector<int>> prec;
int dp[210][21];
int M,C;

int gasto(int g,int m){
    if(m<0) return -inf;
    if(g==C) return M-m;
    if(dp[m][g]!=-1) return dp[m][g];
    int ans = -inf;
    for(auto u:prec[g]){
        ans = max(ans,gasto(g+1,m-u));
    }
    dp[m][g]=ans;
    return ans;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin >> M >> C;
        prec.clear();
        prec.resize(C);
        forc(i,C){
            int k; cin >> k;
            forc(j,k){
                int a; cin >> a;
                prec[i].pb(a);
            }
        }
        memset(dp,-1,sizeof(dp));
        int ans = gasto(0,M);
        if(ans>0) cout << ans << endl;
        else cout << "no solution" << endl;
    }
    return 0;
}