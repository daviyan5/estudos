#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    LL diff=0;
    vector<LL> v;
    for(int i=0;i<n;i++){
        LL a,b; cin >> a >> b;
        diff-=a;
        v.push_back(2*a+b);
    }
    sort(v.begin(),v.end());
    int ans=0;
    int i=n-1;
    while(diff<=0){
        diff+=v[i];
        i--;
        ans++;
    }
    cout << ans << endl;
    return 0;
}