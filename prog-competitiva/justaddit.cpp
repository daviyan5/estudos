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

LL solve(LL base,LL exp, LL mod){
    base %= mod;
    LL ans = 1;
    while(exp > 0){
        if(exp & 1) ans = (ans*base)%mod;
        base = (base*base)%mod;
        exp >>= 1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    LL n,k,m = 10000007;
    while(cin >> n >> k){
        if(n == 0 && k == 0) break;
        LL ans = (solve(n,k,m) + solve(n,n,m) + 2*(solve(n-1,n-1,m) + solve(n-1,k,m))) % m;
        cout << ans << endl;
    }
    return 0;
}