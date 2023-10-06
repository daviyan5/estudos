#include <bits/stdc++.h>
using namespace std;

string numDiv(long n){
    long ans = 1;
    while(n%2 == 0){
        n = n/2;
        ans++;
    }
    for(int i=3;i<=sqrt(n);i+=2){
        long res = 1;
        while(n % i == 0){
            n = n / i;
            res++;
        }
        ans = ans * res;
    }
    if(n > 2) ans *= 2;
    if(ans % 2) return "yes";
    else return "no";

}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    while(true){
        long n; cin >> n;
        if(n == 0) break;
        cout << numDiv(n) << endl;
    }
    return 0;
}