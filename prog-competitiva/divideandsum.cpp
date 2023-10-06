#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;

vector<LL> a;
vector<LL> pref;
map<LL,LL> ans;

void mont(int l,int r){
    LL mid = (a[l]+a[r])/2;
    ans[pref[r]-pref[l-1]]=1;
    LL pos = LL(upper_bound(a.begin()+l, a.begin() + r + 1, mid) - a.begin());
    if(pos <= r){
        mont(l, pos - 1);
        mont(pos, r);
    }
    return;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        ans.clear();
        int n,q; cin >> n >> q;
        a.resize(n+1);
        pref.resize(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        sort(a.begin(),a.end());
        for(int i=1;i<=n;i++) pref[i]=pref[i-1]+a[i];
        mont(1, n);
        LL x;
        while(q--){
            cin >> x;
            if(ans[x] == 1) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}