#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int LL;
typedef long double LD;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    LL t; cin >> t;
    while(t--){
        LL n; cin >> n;
        map<LL,LL> mapa;
        LL soma=0;
        LL ans=0;
        for (int i = 0; i < n; i++){
            LL a; cin >> a;
            soma+=a;
            if(soma==0) ans++;
            if(mapa[soma]>0){
                ans+=mapa[soma];
            }
            mapa[soma]++;
        }
        cout << ans << endl;
        
    }
}