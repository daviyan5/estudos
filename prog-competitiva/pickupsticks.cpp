#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    while(true){  
        int n,m; cin >> n >> m;
        if(n==0 && m==0) break;
        vector<vector<int>> graf(n+1);
        map<int,int> grauE;
        forc(i,m){
            int a,b; cin >> a >> b;
            //a > b
            grauE[b]++;
            graf[a].push_back(b);
        }
        bool foi=true;
        vector<int> ans;
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(grauE[i]==0) q.push(i);
        }
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto u:graf[front]){
                grauE[u]--;
                if(grauE[u]==0){
                    q.push(u);
                }
            }
        }
        if(ans.size()==n) for(auto u:ans) cout << u << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}