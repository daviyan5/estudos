#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    cin.ignore();
    while(t--){
        string aux; getline(cin,aux);
        stack<char> s;
        for(auto u:aux){
            if(s.empty() || u=='A') s.push(u);
            else s.pop();
        }
        cout << s.size() << endl;

    }
}