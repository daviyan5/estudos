

#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define forc(i, n) for(int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for(int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;

vector<bool> vis;
vector<bool> vis2;
vector<bool> svis;
vector<vector<int> > graf;
vector<vector<int> > graf2;

bool temCiclo(int pos, vector<vector<int> > &g, vector<bool> &v){
    svis[pos] = true;
    for(auto u: g[pos]){
        if(svis[u]){
            svis[pos]=false;
            return true;
        }
        else if(!v[u] && temCiclo(u, g, v)){
            svis[pos]=false;
            return true;
        }
    }
    svis[pos] = false;
    v[pos] = true;
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n,m; 
    cin >> n >> m;

    graf.resize(n+1); graf2.resize(n+1);
    vis.resize(n+1); svis.resize(n+1); vis2.resize(n+1);

    fill(vis.begin(),vis.end(),false);
    fill(svis.begin(),svis.end(),false);

    forc(i,m){
        int a,b; //a<b
        cin >> a >> b;
        graf[b].push_back(a);
        graf2[a].push_back(b);
    }

    string res(n,'E');
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i] && !vis2[i]){
            res[i-1] = 'A';
            ans++;
        }
        bool a1 = temCiclo(i, graf, vis);
        bool a2 = temCiclo(i, graf2, vis2);
        if(a1 || a2){
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << ans << endl;
    cout << res << endl;
    return 0;
}

