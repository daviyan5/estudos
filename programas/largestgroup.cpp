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
int N;
string binar(int mask){
    string aux="";
    while(mask>0){
        aux+= mask%2 +'0';
        mask/=2;
    }
    while(aux.size()<=N) aux+='0';
    reverse(aux.begin(),aux.end());
    return aux;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n,p; cin >> n >> p;
        N = n;
        vector<vector<int>> amigos(n);
        vector<int> masks(n);
        forc(i,p){
            int a,b;
            cin >> a >> b;
            a--; b--;
            amigos[a].pb(b);
        }
        //cout << endl;
        forc(i,n){
            int mask = 0;
            for(auto u:amigos[i]){
                mask = mask | (1<<u);
            }
            masks[i] = mask;
            //cout << i <<" "<< binar(mask) << endl;
        }
        //cout << endl;
        int ans = 0;
        for(int i=0;i<(1<<n);i++){
            int mask = -1;
            for(int j=0;j<n;j++){
                if((1<<j) & i) {
                    if(mask == -1) mask = masks[j];
                    else mask = mask & (masks[j]);
                }
            }
            if(mask == -1){
                mask = 0;
            }
            //cout << binar(mask) << " " << binar(i) << endl;
            ans = max(ans, __builtin_popcount(i) + __builtin_popcount(mask));
        }
        cout << ans << endl;
    }
    return 0;
}