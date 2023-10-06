#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n,t;
    while(cin >> n >> t){
        map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            adj[a].push_back(i+1);
        }
        while (t--){
            int e,k; cin >> k >> e;
            if(adj[e].size() < k) cout << "0" << endl;
            else cout << adj[e][k-1] << endl;
        }
    }
    return 0;
}