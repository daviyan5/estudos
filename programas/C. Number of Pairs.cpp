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
    while(t--){
        LL n,l,r; cin >> n >> l >> r;
        vector<LL> v(n);
        forc(i,n){
            cin >> v[i];
        }
        sort(all(v));
        LL ans = 0;
        int pnt = 0;
        int low = n-1, high = n-1;
        while(pnt <= high){
            low = max(pnt, low);
            while (low > pnt and v[pnt] + v[low] >= l){
                low--;
            }
            while (high > low and v[pnt] + v[high] > r){
                high--;
            }
            ans += (high-low);
            pnt++;
        }
        cout << ans << endl;
    }
    return 0;
}