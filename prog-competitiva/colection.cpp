#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    set<int> conj;
    vector<int> aux;
    while(n--){
        int a; cin >> a;
        aux.push_back(a);
        conj.insert(a);
    }
    cout << aux.size()- conj.size() << endl;
    return 0;
}