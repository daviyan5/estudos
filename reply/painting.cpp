#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp(a, b) make_pair(a, b)
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef long double LD;
map<dd,vector<dd>> pontos;
vector<vector<dd>> poli;
map<dd,int> vis;

void achaInt(dd r1,dd r2){
    if(r1.first - r2.first != 0){
        double x= (r2.second - r1.second)/r1.first - r2.first;
        double y= (r1.first*r2.second - r2.first*r1.second)/r1.first - r2.first;
        pontos[r1].push_back(mp(x,y));
        pontos[r2].push_back(mp(x,y));
    }
}

void achaCiclo(dd r1,int c){
    poli[c].push_back(r1);
    vis[r1]=1;

    vis[r1]=2;
    return;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    int aux=1;
    ofstream arq;
    arq.open("out.in");
    while(t--){
        poli.clear();
        pontos.clear();
        vis.clear();
        int n; cin >> n;
        vector<pair<double,double>> retas; //first = m second =q
        forc(i,n){
            double m,q; cin >> m >> q;
            retas.push_back(mp(m,q));
        }
        for(int i=0;i<n;i++){ // acha os pontos de interseção
            for(int j=i+1;j<n;j++){
                achaInt(retas[i],retas[j]);
            }
        }

        arq << "Case #" << aux << ": " << endl;
        aux++;
    }
    return 0;
}