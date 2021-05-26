#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define x first
#define y second
#define all(cc) (cc).begin(),(cc).end()
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX= 2010;
int biton(int N, int pos) {return N = N | (1 << pos);}
int bitoff(int N, int pos) {return N = N & ~(1 << pos);}

struct Node{
    int c; int sz = 1; 
    vector<int> edge,sub;
};
int n,root; 
bool vis[MX] = {false};
vector<Node> grafo(MX);

void printa(Node aux){
    cout <<"c: " <<  aux.c << " sz: " << aux.sz << endl;
    for(auto u:aux.edge){
        cout << "Aresta para " << u << " ";
    }
    cout << endl;
}
void DFS(int pos){
    //cout << "Nó " << pos << endl;
    //printa(grafo[pos]);
    vis[pos] = true;
    for(auto u: grafo[pos].edge){
        if(!vis[u]){
            DFS(u);
            for(auto v: grafo[u].sub){
                grafo[pos].sub.push_back(v);
            }
            grafo[pos].sz += grafo[u].sz;
        }
    }
    if(grafo[pos].c >= grafo[pos].sz){
        cout << "NO" << endl;
        exit(0);
    }
    else{
        grafo[pos].sub.insert(grafo[pos].sub.begin() + grafo[pos].c ,pos);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n;
    for(int i=1;i<=n;i++){
        int p,c; cin >> p >> c; 
        grafo[i].c = c;
        if(p){
            grafo[i].edge.push_back(p);
            grafo[p].edge.push_back(i);
        }
        else root = i;
    }
    DFS(root);
    int ans[MX];
    for(int i=0;i<n;i++){
        ans[grafo[root].sub[i]] = i;
    }
    cout << "YES" << endl;
    for(int i = 1; i<=n; i++){
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
        
    return 0;
}