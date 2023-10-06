#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;

vector<vector<int>> graf;
vector<int> grauEntrada;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    while(true){
        graf.clear();grauEntrada.clear();
        int v,e; cin >> v >> e;
        if(v==0 and e==0) break;
        graf.resize(v+1); grauEntrada.resize(v+1);
        fill(grauEntrada.begin(),grauEntrada.end(),0);
        for(int i=0;i<e;i++){ 
            int a,b; cin >> a >> b;
            graf[a].push_back(b); // b depende de a
            grauEntrada[b]++; //b depende de mais um
        }
        queue<int> f;
        for(int i=1;i<=v;i++){
            if(grauEntrada[i]==0) f.push(i); //quem n tem dependencia
        }
        //BFS
        while(!f.empty()){
            int u=f.front();
            cout << u << ' ';
            f.pop();
            for(auto g:graf[u]){
                grauEntrada[g]--;
                if(grauEntrada[g]==0) f.push(g);
            }
        }
        cout << endl;
    }
    return 0;
}