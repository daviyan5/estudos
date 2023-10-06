#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
bool possivel(vector<int> &a,int m,int k){
    for(auto u:a){
        int num=(u-1)/m;
        k-=num;
    }
    return k>=0;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int l=0;
    int r=a[n-1];
    while(l<r-1){
        int m=(l+r)/2;
        if(possivel(a,m,k)){ 
            r=m;
        }
        else l=m;
    }
    cout << r << endl;
    return 0;
}