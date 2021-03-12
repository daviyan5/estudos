#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t;cin >> t;
    while(t--){
        int x; cin >> x;
        int maxi=0,mini=0;
        int i,j;
        string smax="";
        string smin="";
        for (i = 9, j=1; i >0; i--,j++){
            smax+=to_string(i);
            smin+=to_string(j);
            maxi+=i;
            mini+=j;
            if(maxi>=x) break;
        }
        if(x>maxi){
            cout << -1 << endl;
        }
        else{
            cout << smin << endl;
            cout << smax << endl;
            cout << maxi << endl;
            cout << mini << endl;
            for (int i = smin.length()-1; i >= 0; i--){
                for (int j = smin[i]; j < 10; j++){
                    smin[i]=j;
                    if(atoi(smin)==x){
                        foi=true;
                    }
                }
                
            }
            

        }
        
        
        
    }
}