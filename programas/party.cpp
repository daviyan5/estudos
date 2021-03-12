#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    ofstream arq;
    arq.open("out.in");
    LL t; cin >> t;
    LL aux=1;
    while(t--){
        LL n; cin >> n;
        LL soma=0;
        forc(i,n){
            int a; cin >> a;
            if(a>0) soma+=a;
        }
        arq << "Case #" << aux << ": " << soma << endl;
        aux++;
    }
    return 0;
}
