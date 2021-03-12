#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long LL;
typedef long double LD;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin.ignore();
        int n,h; cin >> n >> h;
        string s(n,'0');
        for(int i=n-1;i>n-h-1;i--){
            s[i]='1';
        }
        do{
            int count=0;
            for(auto u:s){
                if(u=='1') count++;
            }
            if(count == h) cout << s << endl;

        }while(next_permutation(s.begin(),s.end()));
        if(t>0)cout << endl;
    }
    return 0;
}