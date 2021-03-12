#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'

vector<int> base3(int n){
    vector<int> aux;
    while(n>0){
        aux.push_back(n%3);
        n/=3;
    }
    aux.push_back(0);
    return aux;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> maior=base3(n);
        int ans=0;
        int sz=maior.size();
        for(int i=0;i<sz;i++){
            if(maior[i]>=2){
                maior[i+1]++;
                for(int k=i;k>=0;k--){
                    maior[k]=0;
                }
            }
        }
        for (int i = 0; i < sz; i++){
            ans+=maior[i]*pow(3,i);
        }
        
        cout << ans << endl;
    }
}