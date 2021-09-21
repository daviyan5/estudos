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
int dp[101][101];
int minD(int l,int r,string &s){
    if (l > r) return 0;
    else if (l == r) return 1;
    else if (dp[l][r] != -1) return dp[l][r];
    int ans = 1 + minD(l+1,r,s);
    for (int i = l + 1; i <= r;i++) {
        if (s[l] == s[i]) ans = min(ans, minD(l+1,i-1,s)+ minD(i,r,s));
    }
    return dp[l][r] = ans;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n,a,b; 
        cin >> n >> a >> b;
        string s;
        cin >> s;
        if(b > 0){
            cout << n * a + n * b << endl;
        }
        else{
            memset(dp,-1,sizeof(dp));
            cout << n * a + minD(0,n-1,s) * b << endl;
        }
    }
    return 0;
}