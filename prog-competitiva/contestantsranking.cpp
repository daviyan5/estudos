#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<string,vector<string>> adj;
        map<string,bool> vis;
        map<string,int> rank;
        forc(i,n){
            string c1,c2,c3;
            cin >> c1 >> c2 >> c3;
            adj[c1].push_back(c2); adj[c1].push_back(c3);
            adj[c2].push_back(c1); adj[c2].push_back(c3);
            adj[c3].push_back(c1); adj[c3].push_back(c2);
            vis[c1]=false; vis[c2]=false; vis[c3]=false;
        }
        queue<string> q;
        vis["Ahmad"]=true;
        rank["Ahmad"]=1;
        q.push("Ahmad");
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> f;
        f.push(make_pair(1,"Ahmad"));
        while(!q.empty()){
            string top=q.front();
            q.pop();
            for(auto u:adj[top]){
                if(!vis[u]){
                    q.push(u);
                    vis[u]=true;
                    rank[u]=rank[top]+1;
                    f.push(make_pair(rank[u],u));
                }
                else rank[u] = min(rank[u],rank[top]+1);
            }
        }
        priority_queue<string,vector<string>,greater<string>> und;
        for(auto u:adj){
            if(rank[u.first]==0) und.push(u.first);
        }
        int sz = f.size() + und.size();
        cout << sz << endl;
        while(!f.empty()){
            pair<int,string> ans=f.top();
            f.pop();
            cout << ans.second << " " << ans.first-1 << endl;
        }
        while(!und.empty()){
            string top=und.top();
            und.pop();
            cout << top << " undefined" << endl;
        }
    }
    return 0;
}