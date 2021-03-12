#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int q; cin>>q;
    while (q--){
        int n; cin>>n;
        vector<int> vec(n);
        int ntimes=1;
        for (int i = 0; i < n; i++){
            cin >> vec[i];
            for (int j = i-1; j >= 0; j--){
                if(abs(vec[i]-vec[j])<=1) ntimes=2;
            }
        }
        cout << ntimes << endl;
    }
}   