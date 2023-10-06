#include <bits/stdc++.h>
using namespace std;
const int MX = 1e6 + 10;
int sz[MX], root[MX];

void build(set<int> &dif){
    for(auto &u:dif){
        sz[u] = 1;
        root[u]=u;
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
        else root[a] = b;
        sz[a] += sz[b];
        sz[b] = sz[a];
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    set<int> dif;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(n-1 < 2*i){
            if(v[i] != v[n-1-i]){
                dif.insert(v[i]);
                dif.insert(v[n-1-i]);
            }
        }
    }
    build(dif);
    int l = 0; int r = n - 1;
    while(l < r){
        if(v[l] != v[r]){
            join(v[l],v[r]);
        }
        l++; r--;
    }
    int ans = 0;
    map<int,bool> vis;
    for(auto &u:dif){
        int rt = find(u);
        if(!vis[rt]){
            vis[rt] = true;
            ans += sz[rt] - 1;
        }
    }
    printf("%d\n",ans);
    return 0;
}