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

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    int aux = 1;
    while(t--){
        LL p,l; cin >> p >> l;
        printf("Case %d: ",aux);
        // p mod q = l -> q divides (p-l);
        LL sub = p-l;
        if(sub < l){
            printf("impossible\n");
            continue;
        }
        if(p == 0 && l == 0){
            printf("1\n");
            continue;
        }
        vector<LL> ans;
        for(LL i = 1;i<=sqrt(sub);i++){
            if(sub%i == 0){
                if(i > l) ans.pb(i);
                if(sub/i != i && sub/i > l) ans.pb(sub/i);
            }
        }
        sort(all(ans));
        if(ans.empty()) printf("impossible\n");
        else{
            LL sz = ans.size();
            for(LL i=0;i<sz;i++){
                if(i<sz-1) printf("%lld ",ans[i]);
                else printf("%lld",ans[i]);
            }
            printf("\n");
        }
        aux++;
    }
    return 0;
}