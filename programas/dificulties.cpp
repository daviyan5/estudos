#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v;
        map<int,int> m;
        forc(i,n){
            int a; cin >> a;
            v.push_back(a);
        }
        int ans=0;
        sort(v.begin(),v.end());
        for(int i=1;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int soma=2*v[i]-v[j];
                if(binary_search(v.begin(),v.begin()+i,soma)) ans+=m[soma];
            }
        }
        
        cout << ans << endl;
        
    }
    return 0;
}