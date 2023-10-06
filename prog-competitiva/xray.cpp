#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;

int total = 0;
vector<int> v;

int solve(int l, int r, int mn){
    if(l >= r) return 0; 
    int minIndex = int(min_element(v.begin() + l, v.begin() + r) - v.begin());
    int minimum = v[minIndex];
    return solve(l, minIndex, minimum) + solve(minIndex + 1, r, minimum) + minimum - mn;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    int aux=1;
    ofstream arq;
    arq.open("out.in");
    while(t--){
        int n; cin >> n;
        v.resize(n);
        for(auto &a: v) cin >> a;
        total = solve(0, n, 0);
        arq << "Case #" << aux << ": " << total << endl;
        aux++;
        v.clear();
    }
    return 0;
}


