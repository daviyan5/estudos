#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<string> arr;
vector<vector<bool>> vis;
int ex=-1,ey=-1;
int sx=-1,sy=-1;
int m,n;

bool solve(int i,int j){
    if(i>=m || j>=n || i<0 || j<0) return false;
    if(arr[i][j]=='#' || vis[i][j]) return false;
    if(i==sx && j==sy) return true;
    vis[i][j]=true;
    bool up=solve(i-1,j);
    bool down=solve(i+1,j);
    bool right=solve(i,j+1);
    bool left=solve(i,j-1);
    return (up || down || right || left);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        bool vai=true;
        cin >> m >> n;
        cin.ignore();
        arr.clear();
        arr.resize(m);
        vis.clear();
        vis.resize(m);
        ex=-1; ey=-1;
        sx=-1; sy=-1;
        for (int i = 0; i < m; i++){
            arr[i].resize(n);
            vis[i].resize(n);
            getline(cin,arr[i]);
            for (int j = 0; j < n; j++){
                vis[i][j]=false;
                if((j==0 or j==n-1 or i==0 or i==m-1) and arr[i][j]=='.' and vai){
                    if(ex==-1){
                        ex=i;
                        ey=j;
                    }
                    else if(sy==-1){
                        sx=i;
                        sy=j;
                    }
                    else vai=false;
                }
            }
        }
        if(!vai || !solve(ex,ey)){
            cout << "invalid" << endl;
        }
        else{
            cout << "valid" << endl;
        }
    }
    return 0;
}