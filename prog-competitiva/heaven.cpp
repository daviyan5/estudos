#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int  n,a;
    double p;
    cin >> n >> a >> p; 
    p/=100;
    double res = n + a*(2*p-1);
    cout << fixed;
    cout << res << endl;
}