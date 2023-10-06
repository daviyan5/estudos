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
        LL n; cin >> n;
        LL tmp = 0, ans = 0;
        LL len = log10(n) + 1;
        for (int i = 0; i < len; i++) {
            tmp = tmp * 10 + 1;
            for (int j = 1; j <= 9; j++) {
                if ((tmp * j) <= n) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}