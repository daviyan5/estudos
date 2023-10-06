#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n;cin >> n;
    vector<int> q;
    int Sq=0;
    for(int i=0;i<n-1;i++){
        int a; cin >> a;
        Sq+=a;
        q.push_back(a);
    }
    vector<int> p;
    p.push_back(n-Sq);
    for(int i=0;i<n-1;i++){
        p.push_back(p[i]+q[i]);
    }
    vector<int> aux=p;
    sort(aux.begin(),aux.end());
    for(int i=0;i<n;i++){
        p[i]-=aux[0];
        p[i]++;
    }
    aux=p;
    sort(aux.begin(),aux.end());
    bool ok=true;
    for(int i=0;i<n;i++){
        if(aux[i]!=i+1) ok=false;
    }
    if(!ok) cout << "-1" << endl;
    else{
        for(int i=0;i<n;i++){
            cout << p[i] << " ";
        }
        cout << endl;
    }
    return 0;
}