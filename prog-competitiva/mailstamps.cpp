#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
map<int,vector<int>> graf;
map<int,bool> vis;
int e;
void dfs(int pos){
    if(pos==e) return;
    vis[pos]=true;
    for(auto u:graf[pos]){
        if(!vis[u]){
            cout << u << " ";
            dfs(u);
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    int start=-1;
    for(auto u:graf){
        if(u.second.size()==1){
            if(start==-1) start=u.first;
            else{
                e=u.first;
                break;
            }
        }
    }
    cout << start << " ";
    dfs(start);
    return 0;
}