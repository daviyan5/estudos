#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define forc(i, n) for(int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for(int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;


int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    cin.ignore();
    while(t--){
        cin.ignore();
        map<char,vector<char>> graf;
        map<char,int> grauE;
        string el; getline(cin,el);
        string co; getline(cin,co);
        cout << el << co << endl;
        vector<char> a;
        for(auto u:el){
            if(u!=' '){
                a.push_back(u);
            }
        }
        for(int i=0;i<co.size();i++){
            if(co[i]=='>'){
                graf[co[i-1]].push_back(co[i+1]);
                grauE[co[i+1]]++;
            }
            if(co[i]=='<'){
                graf[co[i+1]].push_back(co[i-1]);
                grauE[co[i-1]]++;
            }
        }
        queue<char> in;
    }
    return 0;
}
