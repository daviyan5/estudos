#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool cut(int w, int h, int n, int total){
    if((w%2==1 and h%2==1) or total >= n){
        if(total<n) return false;
        else return true;
    }
    else{
        printf("w = %d h = %d total = %d\n",w,h,total);
        if(w%2==0) cut(w/2,h,n,2*total);
        else if(h%2==0) cut(w,h/2,n,2*total);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int w,h,n;
        cin >> w >> h >> n;
        int total=1;
        bool foi = cut(w,h,n,total);
        if(foi) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}