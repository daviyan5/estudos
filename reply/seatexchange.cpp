#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp(a, b) make_pair(a, b)
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
const int LIM = 1e6 + 10; 
typedef long long LL;
typedef pair<int,int> ii;
typedef long double LD;
typedef vector<vector<int>> grafo;

int sz[LIM], root[LIM];

int find(int a){
    if(a == root[a]) return a;
    return root[a] = find(root[a]);
}
 
void join(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(sz[a] < sz[b])
            root[b] = a;  
        else root[a] = b;
        sz[a] += sz[b];
        sz[b] = sz[a];
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    int aux = 1;
    ofstream arq;
    arq.open("out2.in");
    while(t--){
        int n, k; cin >> n >> k;
        for(int i = 0; i < n; i++){
            root[i] = i;
            sz[i] = 1;
        }
        vector<int> adj(n);
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            adj[i] = a;
            if(find(i) != find(a)){
                join(i, a);
            }
        }
        forc(i, n) find(i);
        arq << "Case #" << aux << ": ";
        for(int i = 0; i < n; i++){
            int r = k;
            int aux = i;
            while(r>0){
                aux = adj[aux];
                r--;
            }
            arq << aux << " ";
        }
        arq << endl;
        aux++;
        adj.clear();
    }
    return 0;
}


/*
Case #1: 5 4 1 6 2 0 3 

1
7 10
3 4 1 5 2 6 0

1
5 2 
0 4 3 1 2

*/

/*int i=0; // posição no v
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
        }*/

/*vector<int> p(n), orig(n);
        vector<vector<int>> v;
        map<vector<int>,bool> m;
        for(int i = 0; i < n; i++) {
            cin >> p[i];
            orig[i] = i;
        }
        // a ideia é, pra cada elemento i, achar a linha e tirar o resto do tamanho da linha a partir daquela posição
        v.push_back(orig);
        vector<int> prov(n);
        for(int j = 0; j < n; j++){
            prov[p[j]] = orig[j];
        }
        v.push_back(prov);

        for(int i = 1; i < k; i++){
            vector<int> atual(n);
            vector<int> anterior;
            anterior = v[v.size()-1];
            for(int j = 0; j < n; j++){
                atual[p[j]] = anterior[j];
            }
            v.push_back(atual);
            bool ok = m[atual];
            if(ok) break;
            m[atual]=true;
        }
        */