#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int maior(int i,int n,vector<bool>& vis,vector<int>& arr,vector<int>& score){
    if(vis[i]) return score[i];
    vis[i]=true;
    if(i+arr[i] < n){
        score[i]=maior(i+arr[i],n,vis,arr,score);
        score[i]+=arr[i];
    }
    else{
        score[i]=arr[i];
    }
    return score[i];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr;
        vector<int> score(n,0);
        for(int i=0;i<n;i++){
            int a; cin >> a;
            arr.push_back(a);
        }
        vector<bool> vis(n,false);
        int s=0;
        for(int i=0;i<n;i++){
            s = max(s,maior(i,n,vis,arr,score));
        }
        cout << s << endl;
        
    }
}