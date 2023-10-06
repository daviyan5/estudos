#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k; //se n é par, kmodn, se não, (k+npulos)modn
        k--;
        int pulos=n/2;
        if(n%2==0) cout << k%(n)+1 << endl;
        else cout << (k+k/pulos)%n+1 << endl; //a cada n/2 passos, k aumenta em 1, então precisamos saber quantos n/2 pulos ocorrem em k passos

    }
    return 0;
}