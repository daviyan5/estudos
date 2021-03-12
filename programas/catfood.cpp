#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int l,r; cin >> l >> r;
        if(l>r/2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}