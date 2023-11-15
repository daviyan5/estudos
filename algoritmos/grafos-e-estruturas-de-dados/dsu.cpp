#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int MX = 1e6 + 10;

int sz[MX], root[MX];

void build(int n){
    for(int i = 0; i < n; i++){
        sz[i] = 1;
        root[i] = i;
    }
}

int find(int a){
    if(a == root[a]) return a;
    return root[a] = find(root[a]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(sz[a] < sz[b])
            root[b] = a;  
        else 
            root[a] = b;
        sz[a] += sz[b];
        sz[b] = sz[a];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n; // number of elements
        cin >> n;

        build(n);

        // Example usage
        join(0, 1);
        join(2, 3);

        if(find(0) == find(1))
            cout << "0 and 1 are connected." << endl;
        else
            cout << "0 and 1 are not connected." << endl;

        if(find(2) == find(3))
            cout << "2 and 3 are connected." << endl;
        else
            cout << "2 and 3 are not connected." << endl;
    }
    return 0;
}
