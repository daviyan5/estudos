#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,f;
    bool ok=true;
    cin >> n >> f;
    string terr[n];
    for (int i = 0; i < n; i++){
       cin >> terr[i];
    }
    for(int i=0; i< n ;i++){
        if (terr[0][0]-48>f){
            break;
            ok=false;
        }
        else terr[0][0]='*';
        for(int j = 0; j< n; j++){
            if(i==0 and j==0) continue;
            if(terr[i][j]-48<=f){
                if(terr[i][j-1]=='*' or terr[i-1][j]=='*') 
                terr[i][j]='*';
            }
        }
    }
    for(int i=n-1; i>=0 ;i--){
        if(!ok) break;
        for(int j=n-1;j>=0;j--){
            if(terr[i][j]-48<=f and terr[i][j]!='*'){
                if(terr[i][j+1]=='*' or terr[i+1][j]=='*') 
                terr[i][j]='*';
            }
        }
    }
    for(int i=0; i<n;i++){
        cout <<terr[i]<< endl;
    }
    return 0;
}