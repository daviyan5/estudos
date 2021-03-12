#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n,d;
        cin >> n >> d;
        bool foi=false;
        priority_queue<int,vector<int>,greater<int>> fila;
        for(int i=0;i<n;i++){
            int a; cin >> a;
            fila.push(a);
            if(a>d) foi=true;
        }
        int min1=fila.top();
        fila.pop();
        int min2=fila.top();
        if(min1+min2<=d || foi==false) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}