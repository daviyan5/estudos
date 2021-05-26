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

void printa(vector<LL> v){
    cout << "Começou" << endl;
    for(auto u:v) cout << u << " ";
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<LL> v(n);
        int ans = 0;
        forc(i,n){
            cin >> v[i];
            if(v[i] <= 0) ans++;
        }
        sort(all(v));
        int mx = v[n-1];
        int first = (upper_bound(all(v),0) - v.begin());
        if(mx <= 0) cout << v.size() << endl;
        else{
            int res = 1;
            int pos = (upper_bound(all(v),0) - v.begin()) - 1;
            while(pos >= 0){
                res++;
                pos = (upper_bound(all(v),v[pos]-v[first]) - v.begin()) - 1;
            }
            ans = max(ans,res);
            cout << ans << endl;
        }
    }
    return 0;
}