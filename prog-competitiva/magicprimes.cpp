#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<string> m(n);
        string s="11";
        for(int i=0;i<n-2;i++) s+='0';
        for(int i=0;i<n;i++){
            m[i]=s;
            reverse(s.begin(),s.begin()+1);
            reverse(s.begin()+1,s.end());
            reverse(s.begin(), s.end());
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}