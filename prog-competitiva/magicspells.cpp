#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;

void monta(string &s,map<char,vector<int>>& cop,int last,int i,string &ans){
    if(cop[s[i]].empty() || i>=s.size()) return;
    auto prox=upper_bound(cop[s[i]].begin(),cop[s[i]].end(),last);
    if(*prox<last || prox==cop[s[i]].end()) return;
    else{
        ans+=s[i];
        monta(s,cop,*prox,(i+1),ans);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    string s; cin >> s;
    int n; cin >> n;
    map<char,vector<int>> cop;
    for(int i=0;i<s.size();i++) cop[s[i]].push_back(i);
    cin.ignore();
    for(int i=0;i<n;i++){
        string aux; cin >> aux; 
        if(cop[aux[0]].empty()) cout << "IMPOSSIBLE" << endl;
        else{ 
            string f="";
            monta(aux,cop,-1,0,f);
            cout << f << endl;
        }
    }
    return 0;
}