#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<long long int> arr;
        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            arr.push_back(a);
        }
        bool troca=true;
        int i=n-1;
        int j=0;
        while(i>=j){
            if(troca){
                cout << arr[j] <<" ";
                j+=1;
                troca=false;
            }   
            else{
                cout << arr[i] <<" ";
                i-=1;
                troca=true;
            }
        }
        cout << endl;
        
    }
    
}