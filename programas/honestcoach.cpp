#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> aux;
        for(int i=0;i<n;i++){
            int a; cin >> a;
            aux.push_back(a);
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=min(ans,abs(aux[i]-aux[j]));
            }
        }
        cout << ans << endl;
    }
}