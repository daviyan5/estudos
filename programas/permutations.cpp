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
const int MX=100;
int dp[MX][MX];
int conta(int n,int k){
    if(n==0) return 0;
    if(k==0) return 1;
    if(dp[n][k]!=0) return dp[n][k];
    else{
        forc(i,k+1){
            if(i<n){
                dp[n][k]+=conta(n-1,k-i);
            }
        }
    }
    return dp[n][k];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        memset(dp,0,sizeof(dp));
        int n,k; cin >> n >> k;
        cout << conta(n,k) << endl;
        
    }
    return 0;
}