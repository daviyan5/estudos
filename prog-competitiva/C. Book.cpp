#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define endl '\n'
const int inf = 0x3f3f3f3f;
const int MX=1e6 + 20;

vector<vector<int>> adj;
int dp[200005];


int solve(int pos){
    dp[pos] = 0;
    int ans = 1;
    for(auto &u:adj[pos]){
        if(dp[u] > 0) ans = max(ans,dp[u] + (pos < u));
        else if(dp[u] == -1){
            int s = solve(u);
            if(s == -1) return -1;
            else ans = max(ans,s + (pos < u));
        }
        else return -1;
    }
    return dp[pos] = ans;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        adj.clear(); adj.resize(n);
        memset(dp,-1,sizeof(dp));
        forc(i,n){
            int k; cin >> k;
            forc(j,k){
                int ch; cin >> ch;
                ch--;
                adj[i].push_back(ch);
            }
        }
        int ans = 1;
        for(int i=0;i<n;i++){
            if(dp[i] > 0) ans = max(ans,dp[i]);
            else{
                int s = solve(i);
                if(s == -1){
                    ans = -1; break;
                }
                else ans = max(ans,s);
            }
        }
        cout << ans << endl;
    }
    return 0;
}