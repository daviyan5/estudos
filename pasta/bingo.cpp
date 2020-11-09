#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,u;
    bool ok=false;
    priority_queue<int, vector<int>, greater<int> > final;
    vector<set<int> > car;
    cin >> n >> k >> u;
    car.resize(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            int q;
            cin >> q;
            car[i].insert(q);
        }
    }
    for (int i = 0; i < u; i++){
        int f;
        cin >> f;
        for (int j = 0; j < n; j++){
            if(car[j].count(f)) car[j].erase(f);
            if(car[j].empty()){
                final.push(j+1);
                ok=true;
            }
        }
        if (ok) break;
    }
    unsigned int sz=final.size();
    for (unsigned int i = 0; i < sz; i++){
        if (ok) cout << final.top();
        else cout << " "<< final.top();
        ok=false;
        final.pop();
    }
    return 0;
}