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

int freq[102];

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    int aux = 1;
    while(t--){
        int n; cin >> n;
        bool vis[102];
        memset(freq,0,sizeof(freq));
        memset(vis,false,sizeof(vis));
        vector<int> prim;
        for(int i=2;i <= n;i++){
            if(!vis[i]){
                for(int j = i; j <= n;j+=i){
                    vis[j]=true;
                    int k = j;
                    while(k%i == 0){
                        k /= i;
                        freq[i]++;
                    }
                }
                prim.pb(i);
            }
        }
        printf("Case %d: %d = ",aux,n);
        aux++;
        int sz = prim.size();
        for(int i=0;i<sz;i++){
            int u = prim[i];
            printf("%d (%d)",u,freq[u]);
            if(i < prim.size()-1) printf(" * ");
        }
        printf("\n");
        
        
        
    }
    return 0;
}