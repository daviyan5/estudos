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
const int MX=1e6 + 20;

int biton(int N, int pos) {return N = N | (1 << pos);}
int bitoff(int N, int pos) {return N = N & ~(1 << pos);}

map<int,int> mPos; // pos no grafo -> pos na matriz
map<int,int> mGrafo; //pos na matriz -> pos no grafo
vector<int> pontos; //pos na matriz dos vertices
int grafo[20][20]; // matriz de adj
char matriz[41][41]; //matriz de char
int dp[20][1 << 20]; //memorização para o caixeiro viajante de tamanho 20*2^20 = 20971520
int n,m,c;

bool bfs(int i,int j){ //djikstra 
    int pos = i*m + j;
    //printf("Pos = %d i = %d j = %d\n",pos,i,j);
    vector<bool> vis(n*m+1,false);
    vector<int> dist(n*m+1,-1);
    queue<int> fila;
    fila.push(pos);
    vis[pos]=true;
    dist[pos]=0;
    while(!fila.empty()){
        int top = fila.front();
        fila.pop();
        int iTop = top/m; int jTop = top%m;
        //printf("i = %d j = %d pos = %d\n",iTop,jTop, top);
        if(iTop>0 && matriz[iTop-1][jTop]!='x'){ //cima
            int at = (iTop-1)*m + jTop;
            if(!vis[at]){
                vis[at]=true;
                dist[at] = dist[top] + 1;
                fila.push(at);
            }
        }
        if(iTop<n-1 && matriz[iTop+1][jTop]!='x'){ //baixo
            int at = (iTop+1)*m + jTop;
            if(!vis[at]){
                vis[at]=true;
                dist[at] = dist[top] + 1;
                fila.push(at);
            }
        }
        if(jTop>0 && matriz[iTop][jTop-1]!='x'){ //esq
            int at = (iTop)*m + jTop-1;
            if(!vis[at]){
                vis[at]=true;
                dist[at] = dist[top] + 1;
                fila.push(at);
            }
        }
        if(jTop<m-1 && matriz[iTop][jTop+1]!='x'){ //dir
            int at = (iTop)*m + jTop+1;
            if(!vis[at]){
                vis[at]=true;
                dist[at] = dist[top] + 1;
                fila.push(at);
            }
        }
    }
    grafo[mGrafo[pos]][mGrafo[pos]] = 0;
    for(auto u: pontos){
        if(u!=pos){
            //printf("Distancia de %d pra %d é %d\n",pos,u,dist[u]);
            if(dist[u] == -1) return false;
            else{
                grafo[mGrafo[pos]][mGrafo[u]] = dist[u];
                grafo[mGrafo[u]][mGrafo[pos]] = dist[u];
            }
        }
    }
    return true;
}
int tsp(int pos,int vis){
    if(vis == (1<<c)-1) return 0;
    if(dp[pos][vis] != -1) return dp[pos][vis];
    int ans = inf;
    for (int i = 0; i < c; i++) {
        if(!(vis & (1<<i)) ){
            ans = min(ans,grafo[pos][i] + tsp(i, vis |(1<<i)));
        }
    }
    if(pos!=-1) dp[pos][vis] = ans;
    return ans;
}
void init(){
    mGrafo.clear();
    mPos.clear();
    pontos.clear();
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    while(true){
        cin >> m >> n;
        //printf("n = %d m = %d\n",n,m);
        if(n == 0 || m == 0 ) break;
        init();
        cin.ignore();
        memset(grafo,-1,sizeof(grafo));
        int com;
        forc(i,n){
            string s;
            getline(cin,s);
            forc(j,m){
                char a = s[j];
                matriz[i][j]=a;
                if(a!= '.' && a!='x'){
                    if(a == 'o') com = i*m + j;
                    else pontos.pb(i*m + j);
                    //cout << i*m + j << endl;
                }
                mGrafo[i*m+j] = -1;
            }
        }
        mGrafo[com] = 0;
        mPos[0] = com;
        c = 1;
        for(auto u:pontos){
            mGrafo[u] = c;
            mPos[c] = u;
            c++;
        }
        int foi=true;
        for(int k=0; k < c; k++){
            int i = mPos[k]/m;
            int j = mPos[k]%m;
            if(!bfs(i,j)){
                printf("-1\n");
                foi = false;
                break;
            }
        }
        if(!foi) continue;
        for(int k=0; k < c; k++){
            for(auto l=0;l<c;l++){
                //printf("Dist de %d ate %d é %d e matriz = %d e %d\n",k,l,grafo[k][l],mPos[k],mPos[l]);
            }
        }
        memset(dp,-1,sizeof(dp));
        int ans = tsp(0,0);
        printf("%d\n",ans);
    }
    return 0;
}