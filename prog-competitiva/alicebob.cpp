#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long int alice(priority_queue<long long int>& arr){
    long long int ans=0;
    if(!arr.empty()){
        ans=arr.top();
        arr.pop();
    }
    return ans%2==0?ans:0;
}
long long int bob(priority_queue<long long int>& arr){
    long long int ans=0;
    if(!arr.empty()){
        ans=arr.top();
        arr.pop();
    }
    return ans%2==1?ans:0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    long long int t; cin >> t;
    while(t--){
        long long int n; cin >> n;
        priority_queue<long long int> arr;
        for(long long int i=0;i<n;i++){
            long long int a; cin >> a;
            arr.push(a);
        }
        bool vez=true;
        long long int pAlice=0, pBob=0;
        while(!arr.empty()){
            if(vez) pAlice+=alice(arr);
            else pBob+=bob(arr);
            vez=!vez;
        }
        if(pAlice>pBob) cout << "Alice" << endl;
        else if(pBob>pAlice) cout << "Bob" << endl;
        else cout << "Tie" << endl;
    }
}