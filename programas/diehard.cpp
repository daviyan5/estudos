#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define pb push_back
//#define endl '\n'
#define x first
#define y second
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX=1003;
int ans[MX][MX];

int dp(int h, int a){
    if(h <= 0 || a <= 0) return -1;
    else if(ans[h][a]==-1){
        ans[h][a] = max(dp(h-2,a-8)+2,dp(h-17,a+7)+2);
    }
    return ans[h][a];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        memset(ans,-1,sizeof(ans));
        int h,a; cin >> h >> a;
        cout << dp(h,a) << endl;
    }
    return 0;
}