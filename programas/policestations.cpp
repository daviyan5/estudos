#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n,k,d; cin >> n >> k >> d;
    map<pair<int,int>,int> ind;
    map<pair<int,int>,bool> foi;
    vector<vector<int>> graf(n+1);
    vector<bool> vis(n+1,false);
    queue<int> in;
    forc(i,k){
        int a; cin >> a;
        in.push(a);
        vis[a]=true;
    }
    forc(i,n-1){
        int a,b; cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
        ind[make_pair(a,b)]=i;
        ind[make_pair(b,a)]=i;
        foi[make_pair(a,b)]=false;
        foi[make_pair(b,a)]=false;
    }
    int ans=0;
    vector<int> roads;
    while(!in.empty()){
        int s=in.front();
        in.pop();
        for(auto u:graf[s]){
            if(vis[u] && !foi[make_pair(u,s)]){
                ans++;
                roads.push_back(ind[make_pair(u,s)]);
                foi[make_pair(u,s)]=true;
                foi[make_pair(s,u)]=true;
            }
            else if(!vis[u]){
                vis[u]=true;
                in.push(u);
            }
            if(ans==k-1){
                queue<int> aux;
                in=aux;
                break;
            }
        }
    }
    cout << ans << endl;
    for(auto u:roads){
        cout << u << " ";
    }
    cout << endl;
    return 0;
}