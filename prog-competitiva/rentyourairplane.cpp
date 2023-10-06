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
const int MX=1000006;

struct Trab{
    int c,f,p;
    bool operator < (const Trab &a){
        return f < a.f;
    }
};

Trab jb[MX];

int prox(int pos){
    int aux = jb[pos].c;
    int l=0;
    int r=pos-1;
    while(l<=r){
        int m = (l+r)/2;
        if(jb[m].f <= aux){
            if(jb[m+1].f < aux){
                l = m+1;
            }
            else return m;
        }
        else r = m-1;
    }
    return -1;
    
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        forc(i,n){
            int c,d,p; cin >> c >> d >> p;
            jb[i].c = c; 
            jb[i].f = c + d;
            jb[i].p = p;
        }
        sort(jb,jb+n); 
        int dp[n];
        dp[0] = jb[0].p;
        for(int i=1;i<n;i++){
            int com = jb[i].p;
            int next = prox(i);
            if(next!=-1) com += dp[next];
            dp[i] = max(com,dp[i-1]);
        }
        cout << dp[n-1] << endl;
    }
    return 0;
}