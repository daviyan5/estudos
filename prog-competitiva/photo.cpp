#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findFriend(int j,int n,vector<pair<int,int>>& arr,vector<int>& pontos){
    for(int i=0;i<n;i++){
        if(i!=j){
            if(arr[i].second < arr[j].second and arr[i].first< arr[j].first){
                return i+1;
            }
            if(arr[i].first < arr[j].second and arr[i].second< arr[j].first){
                return i+1;
            }
            if(arr[i].second > arr[j].second and arr[i].first > arr[j].first){
                pontos[i]=j+1;
            }
            if(arr[i].first > arr[j].second and arr[i].second > arr[j].first){
                pontos[i]=j+1;
            }
            if(arr[i].first==arr[j].first and arr[i].second==arr[j].second){
                if(pontos[i]==-1) return -1;
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++){
            int w,h;
            cin >> w >> h;
            pair<int,int> f; 
            f.first=w; f.second=h;
            arr.push_back(f);
        }
        vector<int> pontos(n,0);
        for (int i = 0; i < n; i++){
            int j;
            if(pontos[i]==0) j=findFriend(i,n,arr,pontos);
            else j=pontos[i];
            pontos[i]=j;
            cout << j << " ";
        }
        cout << endl;
        
    }
}