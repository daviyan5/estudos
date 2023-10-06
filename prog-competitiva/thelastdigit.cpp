#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
typedef long long LL;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        LL exp,base; cin >> base >> exp;
        if(exp == 0){
            cout << "1" << endl;
            continue;
        }
        vector<int> v;
        int dBase = base%10;
        int d = (dBase * dBase)%10;
        v.pb(dBase);
        while(d!=dBase){
            v.pb(d);
            d = (d*dBase)%10;
        }
        int sz = v.size();
        LL ans = (exp-1)%sz;
        cout << v[ans] << endl;
    }
    return 0;
}