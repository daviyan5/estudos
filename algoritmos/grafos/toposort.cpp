#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
vector<vector<int>> graf;
map<int,int> grauE;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int v,e;
    cin >> v >> e;
    graf.resize(v);
    for(int i=0;i<e;i++){ 
        int a,b; cin >> a >> b;
        graf[a].push_back(b); // b depende de a
        grauE[b]++; //b depende de mais um
    }
    queue<int> f;
    for(int i=0;i<v;i++){
        if(grauE[i]==0) f.push(i); //quem n tem dependencia
    }
    //BFS
    vector<int> ans;
    while(!f.empty()){
        int u=f.front();
        ans.push_back(u);
        f.pop();
        for(auto g:graf[u]){
            grauE[g]--;
            if(grauE[g]==0) f.push(g);
        }
    }
    for(auto u:ans){
        cout << u << endl;
    }
    return 0;
}