#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
void sum(vector<LL> &arr,vector<LL> &ans,int l,int r,LL soma){
    if(l>r){
        ans.push_back(soma);
        return;
    }
    sum(arr,ans,l+1,r,soma+arr[l]);
    sum(arr,ans,l+1,r,soma);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    LL n,t; cin >> n >> t;
    vector<LL> b,c;
    for(int i=0;i<n;i++){
        LL a; cin >> a;
        if(i<n/2) b.push_back(a);
        else c.push_back(a);
    }
    LL tempo=0;
    vector<LL> d; vector<LL> e;
    sum(b,d,0,b.size()-1,0);
    sort(d.begin(),d.end(),greater<LL>());
    sum(c,e,0,c.size()-1,0);
    for(auto u:e){
        if(u>t) continue;
        u+=*lower_bound(d.begin(),d.end(),t-u,greater<LL>());
        tempo=max(u,tempo);
    }
    cout << tempo << endl;
    return 0;
}