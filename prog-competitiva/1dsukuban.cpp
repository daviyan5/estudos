#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define forc(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n-1); i >= 0; i--)
typedef long long LL;
typedef long double LD;

int ans(vector<int> &a, vector<int> &b){
    int n = a.size();
    int m = b.size();
    vector<int> c(n), res;
    vector<int> su(n+1);
    int r=m-1;
    ford(i,n){
        su[i] = su[i+1];
        while (r>=0 && b[r]>a[i]) r--;
        if (r>=0 && b[r]==a[i]) su[i]++;
    }
    int soma=0;
    int j=0;
    r=0;
    forc(l, m){
        while (j<n && a[j]<=b[l]+j) j++;
        while (r<m && b[r]-b[l]<j) r++;
        soma = max(soma,r-l+su[j]);
    }
    return soma;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        vector<int> ar,br,al,bl;
        for(int i=0;i<n;i++){
            int a; cin >> a;
            if(a>0) ar.push_back(a);
            else al.push_back(a*(-1));
        }
        for(int i=0;i<m;i++){
            int b; cin >> b;
            if(b>0) br.push_back(b);
            else bl.push_back(b*(-1));
        }
        sort(ar.begin(),ar.end()); sort(al.begin(),al.end());
        sort(br.begin(),br.end()); sort(bl.begin(),bl.end());
        cout << ans(ar,br)+ans(al,bl) << endl;
    }
    return 0;
}