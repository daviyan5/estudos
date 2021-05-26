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

LL dp[MX][2];
vector<ii> range;
vector<vector<int>> adjList;
int n;

int solve(int pos,int in){
    if(dp[pos][in] != -1) return dp[pos][in];
    else{
        dp[pos][in] = 0;
        LL val = !in? range[pos].x : range[pos].y;
        for(auto u:adjList[pos]){
            dp[pos][in] += max(solve(u,0) + abs(val - range[u].x),solve(u,1) + abs(val - range[u].y));
        }
        return dp[pos][in];
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        range.clear(); adjList.clear();
        memset(dp,-1,sizeof(dp));
        cin >> n;
        forc(i,n){
            ii aux;
            cin >> aux.x >> aux.y;
            range.push_back(aux);
        }
        adjList.resize(n);
        forc(i,n-1){
            int u,v; cin  >> u >> v;
            adjList[u-1].push_back(v-1);
        }
        LL ans1 = 0;
        LL ans2 = 0;
        for(auto u:adjList[0]){
            ans1 += max(solve(u,0) + abs(range[0].x - range[u].x),solve(u,1) + abs(range[0].x - range[u].y));
            ans2 += max(solve(u,0) + abs(range[0].y - range[u].x),solve(u,1) + abs(range[0].y - range[u].y));
        }
        cout << max(ans1,ans2) << endl;
    }
    return 0;
}