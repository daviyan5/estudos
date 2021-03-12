#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        long long int n; cin >> n;
        vector<int> div;
        for (long long int i = 1; i < sqrt(n)+1; i++){
            if(n%i==0){
                div.push_back(i);
                if(n/i!=i){
                    div.push_back(n/i);
                }
            }
        }
        bool foi=false;
        for(auto u: div){
            if(n==1) break;
            double r=sqrt((4*n/u-pow(u,2))/3);
            if(r-floor(r)==0 && u>r && (u+(long long int)r)%2==0){
                cout << "YES" << endl;
                foi=true;
                break;
            }
        }
        if(!foi) cout << "NO" << endl;
    }
}