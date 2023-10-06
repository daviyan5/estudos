#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr;
        int tot1=0,tot2=0;
        for(int i=0;i<n;i++){
            int a; cin >> a;
            arr.push_back(a);
            if(a==1) tot1++;
            if(a==2) tot2++;
        }
        bool foi;
        if(tot1%2==1) foi=false;
        else{
            if(tot2%2==1){
                if(tot1>0) foi=true;
                else foi=false;
            }
            else foi=true;
        }
        if(foi) cout <<  "YES" << endl;
        else cout << "NO" << endl;
    }
}