#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    int aux=0;
    while(aux<t){
        //cin.ignore();
        int n,r; cin >> n >> r;
        vector<vector<int>> graf(n);
        vector<int> grauEntrada(n,0);
        for(int i=0;i<r;i++){
            int a,b; cin >> a >> b;
            graf[b].push_back(a);
            grauEntrada[a]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> f;
        queue<int> q;
        map<int,int> rank;
        for(int i=0;i<n;i++){
            if(grauEntrada[i]==0){
                q.push(i);
                f.push(make_pair(0,i));
                rank[i]=0;
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto g:graf[u]){
                grauEntrada[g]--;
                if(grauEntrada[g]==0){
                    q.push(g);
                    rank[g]=rank[u]+1;
                    f.push(make_pair(rank[g],g));
                }
            }
        }
        printf("Scenario #%d:\n",aux+1);
        int idx=0;
        while(!f.empty()){
            pair<int,int> aux=f.top();
            printf("%d %d\n",aux.first+1,aux.second);
            f.pop();
        }
        printf("\n");
        aux++;
    }
    return 0;
}