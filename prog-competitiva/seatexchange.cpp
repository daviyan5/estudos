#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp(a, b) make_pair(a, b)
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef pair<int,int> ii;
typedef long double LD;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    int aux=1;
    ofstream arq;
    arq.open("out2.in");
    while(t--){
        int n,k; cin >> n >> k;
        vector<int> p(n);
        map<int,bool> m;
        map<int, ii> w;
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++) cin >> p[i];
        // a ideia é, pra cada elemento i, achar a linha e tirar o resto do tamanho da linha a partir daquela posição
        int i=0; // posição no v
        for(auto u:p){
            if(m[u]) continue; // se ja tiver ido, continua 
            int pos=u; 
            int j=0; // posição no v[i]
            while(true){
                if(m[pos]) break;
                m[pos]=true; 
                v[i].push_back(pos); 
                pos = p[pos];
                w[pos]=mp(i,j); // mapa que diz o i e o j
                j++;
            }
            i++;
        }
        for(auto u:v){
            for(auto d:u){
                cout << d << " ";
            }
            cout << endl;
        }
        cout << endl;
        arq << "Case #" << aux << ": ";
        for(auto u:p){
            int i=w[u].first;
            int j=w[u].second;
            int at = (w[u].second + k)%(v[w[u].first].size());
            arq << v[w[u].first][at] << " ";
        }
        aux++;
    }
    return 0;
}