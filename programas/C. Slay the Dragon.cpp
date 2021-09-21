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
typedef pair<long long,long long> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX=1e6 + 20;
int biton(int N, int pos) {return N = N | (1 << pos);}
int bitoff(int N, int pos) {return N = N & ~(1 << pos);}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    vector<LL> heroes(n);
    LL sum = 0;
    forc(i,n){
        cin >> heroes[i];
        sum += heroes[i];
    }
    int m; cin >> m;
    vector<ii> dragon(m);
    forc(i,m) cin >> dragon[i].first >> dragon[i].second;
    sort(heroes.begin(),heroes.end());
    for(int i=0;i<m;i++){
        LL ans = 0;
        int pos = (lower_bound(heroes.begin(),heroes.end(),dragon[i].first) - heroes.begin());
        //if(pos < n) cout << heroes[pos] << " ";
        if(pos == n or pos == 0){
            if(pos == n){
                pos--;
                //cout << heroes[pos] << " ";
            }
            ans = max(dragon[i].first - heroes[pos],LL(0)) + max(dragon[i].second - (sum - heroes[pos]),LL(0));
        }
        else{
            LL abs1 = max(dragon[i].first - heroes[pos],LL(0)) + max(dragon[i].second - (sum-heroes[pos]),LL(0));
            LL abs2 = max(dragon[i].first - heroes[pos-1],LL(0)) + max(dragon[i].second - (sum-heroes[pos-1]),LL(0));
            ans = min(abs1,abs2);
        }
        cout << ans << endl;
    }
    return 0;
}