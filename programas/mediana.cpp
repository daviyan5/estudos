#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        priority_queue<int> mn; // aqui ficam os menores que a mediana
        priority_queue<int,vector<int>,greater<int>> mx; // aqui ficam os maiores que a mediana
        while(true){
            int n; cin >> n;
            if(n==0) break;
            if(n==-1){
                
            }
            else{
                if(mn.empty() && mx.empty()){
                    mn.push(n);
                }
                else if(mn.empty()){
                    
                }
                else if(mx.empty()){

                }
                else{

                }
                
            }
        }
    }
    return 0;
}