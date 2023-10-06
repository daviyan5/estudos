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
const int MX=30001;
int dp[MX][505];
int gem[MX];
int n,D;

int solve(int pos,int d){
    int dm = d - D + 250;
    if(pos >= MX) return 0;
    if(dp[pos][dm]!=-1) return dp[pos][dm];
    if(d==1) return dp[pos][dm] = gem[pos] + max(solve(pos+d,d),solve(pos+d+1,d+1));
    else return dp[pos][dm] = gem[pos] + max(max(solve(pos+d,d),solve(pos+d+1,d+1)),solve(pos+d-1,d-1));
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    memset(gem,0,sizeof(gem));
    memset(dp,-1,sizeof(dp));
    cin >> n >> D;
    forc(i,n){
        int a; cin >> a;
        gem[a]++;
    }
    cout << solve(D,D) << endl;
    return 0;
}