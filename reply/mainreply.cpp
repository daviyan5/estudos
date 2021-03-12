#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp(a, b) make_pair(a, b)
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef pair<int,int> ii;
typedef long double LD;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    int aux=1;
    ofstream arq;
    arq.open("out.in");
    while(t--){

        arq << "Case #" << aux << ": " << endl;
        aux++;
    }
    return 0;
}