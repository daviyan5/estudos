#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
bool backtrack(string& s,int pos,map<char,char>& mapa){
    if(pos==3){
        stack<char> st;
        bool foi=true;
        for(auto u:s){
            if(mapa[u]=='(') st.push(u);
            else{
                if(st.empty()){
                    foi=false;
                    break;
                }
                else st.pop();
            }
        }
        if(!st.empty()) foi=false;
        return foi;
    }
    mapa['A'+pos]='(';
    bool ab=backtrack(s,pos+1,mapa);
    mapa['A'+pos]=')';
    bool fe=backtrack(s,pos+1,mapa);
    return (ab || fe);
    
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    cin.ignore();
    while(t--){
        string s; getline(cin,s);
        map<char,char> mapa;
        if(backtrack(s,0,mapa)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}