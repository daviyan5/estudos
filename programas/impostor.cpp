#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n,s; cin >> n >> s;
    set<int> lista;
    for (int i = 0; i < s; i++){
        int a;
        cin >> a;
        lista.insert(a);
    }
    if(lista.size()==(n-1)) cout << "YES" << endl;
    else cout << "NO" << endl;
    
}