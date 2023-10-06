#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp(a, b) make_pair(a, b)
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;
typedef pair<pair<int, int>, pair<int, int>> ii;
const int MOD = 100003;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    int aux=1;
    ofstream arq;
    arq.open("out.in");
    while(t--){
        LL ans = 0;
        int n, m; cin >> n >> m; //nxm
        vector<ii> v;
        int x0, y0;
        cin >> x0 >> y0; 
        int tele; cin >> tele;
        forc(i, tele){
            int xi, yi, xf, yf;
            cin >> xi >> yi >> xf >> yf;
            v.push_back(mp(mp(xi,yi), mp(xf,yf)));
        }
        sort(v.begin(), v.end());
        int x_atual = x0, y_atual = y0;
        while(v.size() != 0){
            int idx = 0;
            LL mn = INT64_MAX;
            forc(i, v.size()){
                auto e = v[i];
                int dist = abs(x_atual - e.first.first) + abs(y_atual - e.first.second);
                if(mn > dist){
                    mn = dist;
                    idx = i;
                }
            }
            ans = ((ans % MOD) + (mn % MOD)) % MOD;
            x_atual = v[idx].second.first, y_atual = v[idx].second.second;
            v.erase(v.begin()+idx);
        }
        arq << "Case #" << aux << ": " << ans << endl;
        aux++;
    }
    return 0;
}

/*
We remind you that the remainder of the division between one number and another
is generally called modulo, and in many programming languages it is performed with
the operator % (e.g. 13 % 5 = 3). Also remember that to avoid overflows is recommended
to do ((A % R) + (B % R)) % R rather than (A + B) % R.

1 
3 3
1 1
3 
0 0 1 2 
0 2 2 0 
2 2 1 0 
*/


