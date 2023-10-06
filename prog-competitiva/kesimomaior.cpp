#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n,q; cin >> n >> q;
    map<int,int> z;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        z[arr[i]]++;
    }
    while(q--){
        int t,x; cin >> t >> x;
        if(t==1){
            z[arr[x]]--;
            z[1-arr[x]]++;
            arr[x]=1-arr[x];
        }
        else{
            if(x>z[1]) cout << "0" << endl;
            else cout << "1" << endl;
        }
    }
    return 0;
}