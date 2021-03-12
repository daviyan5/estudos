#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<int,int> mapa;
        for(int i=0;i<n;i++){
            int a; cin >> a;
            mapa[a%3]++;
        }
        int maior=min(mapa[1],mapa[2]);
        mapa[1]-=maior;
        mapa[2]-=maior;
        maior+=mapa[1]/3+mapa[2]/3;
        cout << mapa[0]+maior << endl;
    }
}