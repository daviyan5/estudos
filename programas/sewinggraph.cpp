#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int,int>> arr;
    map<pair<int,int>,int> mapa;
    for(int i=1;i<=n;i++){
        int x,y; cin >> x >> y;
        arr.push_back(make_pair(x,y));
        mapa[make_pair(x,y)]=i;
    }
    sort(arr.begin(),arr.end());
    cout << 2*n -1 << endl;
    for(int i=0;i<n;i++){
        cout << mapa[arr[i]] << " ";
    }
    for(int i=n-2;i>=0;i--){
        cout << mapa[arr[i]] << " ";
    }
    cout << endl;
    return 0;
}