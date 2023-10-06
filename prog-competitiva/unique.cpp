#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int q; cin >> q;
    while (q--){
        int n; cin >> n;
        set<int> foi;
        vector<int> arr(n+1);
        vector<int> total(n+1);
        fill(total.begin(),total.end(),0);
        priority_queue<int,vector<int>,greater<int>> fila;
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            total[arr[i]]++;
            printf("arr[%d]=%d total[%d]=%d\n",i,arr[i],arr[i],total[arr[i]]);
            if(total[arr[i]]>1){
                foi.insert(arr[i]);
            }
        }
        int ans=INT_MAX,ians=-2;
        for (int i = 0; i < n; i++){
            if(!foi.count(arr[i]) and arr[i]<ans){
                ans=arr[i];
                ians=i;
            }
        }
        cout << ians+1 << endl;
        
    }
    
}