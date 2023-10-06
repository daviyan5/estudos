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


int n;
double dist[17][17];
double dp[1 << 18];
double modulo(ii a,ii b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}
string binar(int mask){
    string aux="";
    while(mask>0){
        aux+= mask%2 +'0';
        mask/=2;
    }
    while(aux.size()<=2*n) aux+='0';
    reverse(aux.begin(),aux.end());
    return aux;
}
double solve(int mask){
    if(mask == 0) return 0;
    if(dp[mask]!=-1) return dp[mask];
    double ans = inf;
    forc(i,2*n){
        if(mask & (1<<i)){ // se tiver ligado
            for(int j=i+1;j<2*n;j++){
                if(mask & (1 << j)){ // se tiver ligado
                    int nMask = mask - (1 << i) - (1 << j);  //desativo os dois bits
                    //cout << binar(nMask) << " " << binar(mask) << endl;
                    ans = min(ans, dist[i][j] + solve(nMask)); 
                }
            }
        }
    }
    return dp[mask] = ans;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int aux =1;
    while(cin >> n){
        if(n == 0) break;
        vector<ii> v(2*n);
        forc(i,2*n){
            string s; cin >> s;
            int a,b; cin >> a >> b;
            v[i] = mp(a,b);
        }
        forc(i,2*n){
            for(int j=i+1;j<2*n;j++){
                double d = modulo(v[i],v[j]);
                dist[i][j] = d;
                dist[j][i] = d;
            }
        }
        forc(i,1<<2*n){
            dp[i] = -1;
        }
        double ans = solve((1<<2*n) - 1);
        printf("Case %d: %.2lf\n",aux,ans);
        aux++;
    }
    return 0;
}