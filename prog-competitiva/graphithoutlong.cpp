#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;

#include <iostream>
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<int>> graf;
vector<bool> entr;
vector<bool> vis;

bool intera(int v,bool g){
    if(vis[v]) return true;
    vis[v]=true;
    entr[v]=g;
    for(auto u: graf[v]){
        if(!intera(u,!g)) return false;
        if(entr[u]==entr[v]) return false;
    }
    return true;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int m,n; cin >> n >> m;
    graf.resize(n+1); vis.resize(n+1); entr.resize(n+1);
    vector<pair<int,int>> res;
    forc(i,m){
        int a,b; cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
        res.push_back(make_pair(a,b));
    }
    if(!intera(1,true)){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        for(auto u:res){
            if(entr[u.first]) cout << "1";
            else cout << "0";
        }
        cout << endl;
    }
    return 0;
}