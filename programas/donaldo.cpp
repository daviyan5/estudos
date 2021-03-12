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
        vector<int> v;
        stack<int> sl,sr;
        for(int i=0;i<n;i++){
            int h,m,s;
            scanf("%d:%d:%d",&h,&m,&s);
            h*=3600;
            m*=60;
            s+=h+m;
            v.push_back(s);
        }
        bool dir=true;
        sort(v.begin(),v.end());
        int sz=v.size();
        int ans=0;
        int inc; cin >> inc;
        if(sz%2!=0){
            if(sz==1 || v[sz-1]-v[sz-2]<inc) ans++;
            sz--;
        }
        for(int i=sz-1;i>=sz/2;i--){
            sr.push(v[i]);
        }
        for(int i=0;i<sz/2;i++){
            sl.push(v[i]);
        }
        int i=1;
        while(!sr.empty() && !sl.empty()){
            int vl=abs(sr.top()-sl.top());
            if(vl/<inc) ans+=1;
            sr.pop(); sl.pop();
            i++;
        }
        
        cout << ans << endl;
    }
    return 0;
}