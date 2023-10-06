#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    long long d,n,m;
    cin >> d >> n >> m;
    vector<pair<long long,long long>> v(m);
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> mnHeap;
    for(int i=0;i<m;i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end());
    long long dist = n;
    long long last = 0;
    long long pont = 0;
    long long ans = 0;
    bool foi = true;
    while(dist < d){
        while(pont < m and v[pont].first <= dist){
            auto par = v[pont];
            swap(par.first,par.second);
            mnHeap.push(par);
            pont++;
        }
        if(mnHeap.empty()){
            foi = false;
            break;
        }
        auto next = mnHeap.top(); mnHeap.pop();

        long long exc = (dist - next.second);
        ans -= last * exc; // tira o excesso
        dist -= exc;
        long long add = min(n,d-dist);
        ans += add * next.first;
        dist += n;
        last = next.first;
    }
    if(!foi) cout << -1 << endl;
    else cout << ans << endl;
}