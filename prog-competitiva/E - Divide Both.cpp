#include <bits/stdc++.h>
using namespace std;
int phi(int n){
    int result = n;
    if(n % 2 == 0){
        while(n % 2 == 0){
            n /= 2;
        }
        result -= result / 2;
    }
    for(int p = 3; p * p <= n; p += 2){   
        if (n % p == 0){
            while (n % p == 0) n /= p;  
            result -= result / p;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int l,r; cin >> l >> r;
    long long ansr = (r+1)*(r)/2;
    long long ansl = (l+1)*(l)/2;
    map<int,bool> vis;
    map<int,int> ans;
    for(int i = 1; i<=r ; i++){
        int cop = vis[i]? ans[i]: phi(i);
        ans[i] = cop;
        vis[i] = true;
        ansr -= cop;
        ansr -= ((r/i) - 1);
    }
    for(int i = 1; i<=l ; i++){
        int cop = vis[i]? ans[i]: phi(i);
        ans[i] = cop;
        vis[i] = true;
        ansl -= cop;
        ansl -= ((l/i) - 1);
    }
    printf("%lld\n",(ansr - ansl)*2);
    return 0;
}