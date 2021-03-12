#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> b,a;
        for(int i=0;i<n;i++){
            int c; cin >> c;
            b.push_back(c);
        }
        int um=0,zero=0;
        for(int i=0;i<n;i++){
            int c; cin >> c;
            if(c==0) zero++;
            else um++;
            a.push_back(c);
        }
        vector<int> org=b;
        sort(org.begin(),org.end());
        if(org==b || (zero>0 && um>0)){
            //tudo certo
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
}