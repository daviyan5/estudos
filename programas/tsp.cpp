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
typedef long long LL;
typedef pair<int,int> ii;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX=1e6 + 20;
int biton(int N, int pos) {return N = N | (1 << pos);}
int bitoff(int N, int pos) {return N = N & ~(1 << pos);}

double grafo[20][20]; int caminhos[20][1 << 20];
double dp[20][1 << 20];
int n,prim;

double dist(ii &a,ii &b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

double solve(int pos, int vis){
    if(vis == (1<<n)-1) return 0;
    if(pos > 0 && dp[pos][vis] != -1) return dp[pos][vis];
    double ans = inf;
    for (int i = 0; i < n; i++) {
        if(!(vis & (1<<i)) ){
            double sum = pos==-1?0:grafo[pos][i];
            double cand = grafo[pos][i] + solve(i, vis |(1<<i));
            if(cand < ans){
                ans = cand;
                if(pos!= -1) caminhos[pos][vis] = i;
                else prim = i;
            }
        }
    }
    if(pos!=-1) dp[pos][vis] = ans;
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int cont = 1;
    while(cin >> n){
        if(n == 0) break;
        printf("**********************************************************\n");
        vector<ii> v;
        forc(i,n){
            int a,b;
            cin >> a >> b;
            v.pb(mp(a,b));
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double d = dist(v[i],v[j])+16.0;
                grafo[i][j] = d;
                grafo[j][i] = d;
            }
        }
        for(int i=0;i<20;i++){
            for(int j=0;j<(1<<20);j++){
                dp[i][j]=-1;
            }
        }
        printf("Network #%d\n",cont);
        double ans = solve(-1,0);
        vector<ii> res;
        int pos = prim;
        int vis = 1 << prim;
        while(vis < (1<<n)-1){
            int a = caminhos[pos][vis];
            res.pb(mp(pos,a));
            pos = a;
            vis = (vis | (1<<a));
        }
        for(auto u:res){
            int i = u.x;
            int j = u.y;
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",v[i].x,v[i].y,v[j].x,v[j].y,grafo[i][j]);

        }
        printf("Number of feet of cable required is %.2lf.\n",ans);
        cont++;
    }
    return 0;
}