#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin.ignore();
        int n; cin >> n;
        vector<LL> a,b,c,d;
        for(int i=0;i<n;i++){
            LL p,q,n,m; cin >> p >> q >> m >> n;
            a.push_back(p);
            b.push_back(q);
            c.push_back(m);
            d.push_back(n);
        }
        vector<LL> s1,s2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                s1.push_back(a[i]+b[j]);
                s2.push_back(c[i]+d[j]);
            }
        }
        sort(s2.begin(),s2.end());
        LL ans=0;
        for(auto u:s1){
            auto l=lower_bound(s2.begin(),s2.end(),-u);
            auto r=upper_bound(s2.begin(),s2.end(),-u);
            ans+=(r-l);
        }
        cout << ans << endl;
        if(t>0) cout << endl;
    }
    return 0;
}