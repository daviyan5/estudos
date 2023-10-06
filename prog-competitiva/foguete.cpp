#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y;
        cin.ignore();
        map<char,int> m;
        string s; getline(cin,s);
        for(auto c:s){
            m[c]++;
        }
        bool foix=false,foiy=false;
        if(x>0 && m['R']>=x) foix=true;
        else if(x<0 && m['L']>=-x) foix=true;
        else if(x==0) foix=true;
        if(y>0 && m['U']>=y) foiy=true;
        else if(y<0 && m['D']>=-y) foiy=true;
        else if(y==0) foiy=true;
        if(foix and foiy) cout << "YES" << endl;
        else cout << "NO" << endl; 
    }
    return 0;
}