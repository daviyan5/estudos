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
const int MX=2005;
int biton(int N, int pos) {return N = N | (1 << pos);}
int bitoff(int N, int pos) {return N = N & ~(1 << pos);}

map<int,map<LL,map<LL,LL>>> dp;
map<int,map<LL,map<LL,bool>>> vis;
int n,mx=INT_MIN,mn=INT_MAX;
priority_queue<int> decr;
priority_queue<int,vector<int>,greater<int>> crec;

LL solve(int pos,int mxA,int mnA){
    if(pos == 0) return 0;
    if(vis[pos][mxA][mnA]) return dp[pos][mxA][mnA];
    LL ans = 0;
    //printf("Na pos %d o max é %d e o min %d\n",pos,mxA,mnA);
    int mnX = crec.top();
    crec.pop();
    ans = solve(pos-1,mxA,mnX);
    crec.push(mnX);
    
    int mxX = decr.top();
    decr.pop();
    ans = min(ans, solve(pos-1,mxX,mnA));
    decr.push(mxX);
    //printf("mnX = %d mxX = %d\n",mnX,mxX);
    //printf("Na pos %d a resposta é %d\n",pos,ans+mxA-mnA);
    vis[pos][mxA][mnA] = true;
    return dp[pos][mxA][mnA] = ans + (mxA - mnA);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n;
    forc(i,n){
        int a; cin >> a;
        mx = max(mx,a);
        mn = min(mn,a);
        decr.push(a);
        crec.push(a);
    }
    crec.pop(); decr.pop();
    cout << solve(n-1,mx,mn) << endl;

    return 0;
}