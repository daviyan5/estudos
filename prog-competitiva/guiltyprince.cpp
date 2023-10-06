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
    int aux=0;
    while(t--){
        int n,m; cin >> m >> n;
        vector<vector<char>> mat(n+1);
        vector<vector<int>> graf(n*m+1);
        vector<bool> vis(n*m,false);
        int posi;
        int idx=0;
        forc(i,n){
            mat[i].resize(m);
            forc(j,m){
                cin >> mat[i][j];
                if(mat[i][j]=='@') posi=i*m+j;
                idx++;
            }
        }
        forc(i,n){
            forc(j,m){
                if(mat[i][j]=='#') continue;
                if(i>=1 && mat[i-1][j]!='#'){ // cima
                    graf[i*m+j].push_back(i*m+j-m);
                }
                if(i+1<n && mat[i+1][j]!='#'){ //baixo
                    graf[i*m+j].push_back(i*m+j+m);
                    
                }
                if(j>=1 && mat[i][j-1]!='#'){ //esquerda
                    graf[i*m+j].push_back(i*m+j-1);
                }
                if(j+1<m && mat[i][j+1]!='#'){ //direita
                    graf[i*m+j].push_back(i*m+j+1);
                }
            }
        }
        queue<int> q;
        q.push(posi);
        vis[posi]=true;
        int ans=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            ans++;
            for(auto u:graf[top]){
                if(!vis[u]){
                    vis[u]=true;
                    q.push(u);
                }
            }
        }
        printf("Case %d: %d\n",aux+1,ans);
        aux++;
    }
    return 0;
}