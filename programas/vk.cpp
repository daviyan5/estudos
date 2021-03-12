#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    LL n; cin >> n;
    unordered_map<LL,vector<LL>> mapa;
    LL total=0;
    vector<LL> vaux;
    for(LL i=0;i<n;i++){
        LL a; cin >> a;
        vaux.push_back(a);
    }
    for(LL i=0;i<n;i++){
        LL t; cin >> t;
        mapa[vaux[i]].push_back(t);
    }
    set<LL> va;
    for(auto u:vaux){
        va.insert(u);
    }
    priority_queue<LL> fila;
    LL custo=0;
    for(auto u:va){ 
        if(mapa[u].size()>1 || !fila.empty()){
            for(auto v:mapa[u]){
                fila.push(v);
                custo+=v;
            }
            custo-=fila.top(); // o maior fica
            fila.pop();
            LL aux=u;
            while(!fila.empty()){
                aux++;
                total+=custo; // o custo é de todos os elementos iguais de uma vez
                if(mapa[aux].size()>0){ // se ja estiver ocupado, proxima iteração
                    break;
                }
                else{ // se não, nos livramos de 1
                    custo-=fila.top();
                    fila.pop();
                }

            }
        }
    }
    cout << total << endl;
    return 0;
}