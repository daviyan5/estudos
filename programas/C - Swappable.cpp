#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    vector<int> v(t);
    for(int i=0;i<t;i++){
        cin >> v[i];
    }
    map<int,int> f;
    long long ans = 0;
    for(int i=t-1;i>=0;i--){
        ans += (t-1-i) - f[v[i]];
        f[v[i]]++;
    }
    printf("%lld\n",ans);
    return 0;
}