#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        LL n; cin >> n;
        // soma de P.A = m*(m+1)<2*n -> m²+m-2n<0 -> m<(sqrt(8*n+1)-1)/2
        LL d= (sqrt(8*n+1)-1)/2;
        cout << d << endl;
        
    }
    return 0;
}