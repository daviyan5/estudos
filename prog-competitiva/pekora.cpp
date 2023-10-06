#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        int ans=0;
        while(true){
            bool com=false;
            int f;
            for(int i=0;i<n;i++){
                if(arr[i]!=1){
                    f=i;
                    com=true;
                    break;
                }
            }
            if(!com) break;
            for(int i=f;i<n;i+=arr[i]){
                arr[i]=max(arr[i]-1,1);
            }
            ans++;
        }
        if(ans>0) ans++;
        cout << ans << endl;
    }
    return 0;
}