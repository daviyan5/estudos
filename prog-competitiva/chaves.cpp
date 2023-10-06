#include <bits/stdc++.h> 
using namespace std; 
//#define endl '\n'

int main() {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    cin.ignore();
    while(t--){
        string s; getline(cin,s);
        int sz=s.size();
        bool ok=true;
        int cont=0;
        for(auto u:s){
            if(u==')') cont--;
            else cont++;
            if(cont<0) ok=false;
        }
        if(cont%2==1 || s[sz-1]=='(') ok=false;
        if(!ok) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
