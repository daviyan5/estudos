#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX=1e6 + 20;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n,m; cin >> n >> m;
    vector<int> arr(n);
    forc(i,n) cin >> arr[i];
    sort(arr.begin(),arr.end());
    LL total=0;
    LL ans[n];
    for(int k=0;k<n;k++){
        total+=arr[k];
        ans[k]=total;
        //cout << total << endl;
        if(k>=m) ans[k]+=ans[k-m];
        cout << ans[k] << " ";
    }
    cout << endl;
    return 0;
}