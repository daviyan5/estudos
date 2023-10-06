#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    string s;
    getline(cin,s);
    stack<char> st;
    for(auto u:s){
        if(st.empty()){
            st.push(u);
        }
        else{
            if(st.top()==u) st.pop();
            else st.push(u);
        }
    }
    if(st.empty()) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}