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
const int MOD = 998244353;
int biton(int N, int pos) {return N = N | (1 << pos);}
int bitoff(int N, int pos) {return N = N & ~(1 << pos);}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    LL dp[n+10] = {0};
    LL sum = 1;
    for (int i=1;i<=n;i++){
        for (int j=i+i;j<=n;j+=i){
            dp[j]++;
        }
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = (dp[i] + sum) % MOD;
        sum = (sum + dp[i]) % MOD;
    }
    cout << dp[n] << endl;
    return 0;
}