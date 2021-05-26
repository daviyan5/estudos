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


int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n+1);
    int dp[n+1][n+1][2];
    forc(i,n){
        cin >> v[i+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j][0] = dp[i][j][1] = inf;
        }
    }
    dp[0][0][0] = dp[0][0][1] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if((v[i] & 1) or !v[i]) {
                dp[i][j][1] = min(dp[i-1][j][1], dp[i-1][j][0] + 1);
                //cout << dp[i][j][1] << endl;
            }
            if(!(v[i] & 1) and j != 0) {
                dp[i][j][0] = min(dp[i-1][j-1][0], dp[i-1][j-1][1] + 1);
                //cout << dp[i][j][1] << endl;
            }
        }
    }
    cout << min(dp[n][n/2][0],dp[n][n/2][1]) << endl;
    return 0;
}