#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void senha(string u, vector<string>& arr, int pos,string dum,int pDum){
    bool pare=false;
    if(pos>=u.length()-1) pare=true;
    if(u[pos]=='#'){
        for(int i=0;i<10;i++){
            dum+=i+'0';
            if(!pare) senha(u,arr,pos+1,dum,pDum+1);
            else{
                cout << dum << endl;
            }
            dum.erase(pDum);
        }
    }
    else{
        for(auto v:arr){
            dum+=v;
            if(!pare) senha(u,arr,pos+1,dum,pDum+v.size());
            else{
                cout << dum << endl;
            }
            dum.erase(pDum);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    cin.ignore();
    vector<string> arr;
    for(int i=0;i<n;i++){
        string ans;
        getline(cin,ans);
        arr.push_back(ans);
    }
    vector<string> pos;
    string line;
    int q=10;
    while(getline(cin,line) and q>0){
        pos.push_back(line);
        q--;
    }
    for(auto u:pos){
        senha(u,arr,0,"",0);
    }
}