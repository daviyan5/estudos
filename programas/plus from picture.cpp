#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n,m; cin >> n >> m;
    vector<vector<char>> mat(n);
    vector<bool> vis(n*m);
    set<int> ast;
    forc(i,n){
        mat[i].resize(m);
        forc(j,m){
            cin >> mat[i][j];
            vis[i*m+j]=false;
            if(mat[i][j]=='*') ast.insert(i*m+j);
        }
    }
    // achar o centro
    int centro;
    bool foi=false;
    for(auto u:ast){
        bool a=false,b=false,c=false,d=false;
        if(u-m>=0  && ast.count(u-m)) a=true;
        if(u+m<m*n  && ast.count(u+m)) b=true;
        if(u-1>=0  && ast.count(u-1)) c=true;
        if(u+1<m*n  && ast.count(u+1)) d=true;
        if(a and b and c and d){
            foi = true;
            centro = u;
            break;
        }
    }
    if(!foi){
        cout << "NO" << endl;
        return 0;
    }
    // marcar todo mundo nos raios do centro
    vis[centro]=true;
    int aux=centro;
    while(ast.count(aux-m)){
        //printf("Subindo: %d\n",aux-m);
        vis[aux-m]=true;
        aux-=m;
    }
    aux=centro;
    while(ast.count(aux+m)){
        //printf("Descendo: %d\n",aux+m);
        vis[aux+m]=true;
        aux+=m;
    }
    aux=centro;
    int i=centro/m;
    while(ast.count(aux-1) and i*m<=aux-1){
        //printf("Esquerda: %d\n",aux-1);
        vis[aux-1]=true;
        aux-=1;
    }
    aux=centro;
    while(ast.count(aux+1) and (i+1)*m>aux+1){
        //printf("Direita: %d\n",aux+1);
        vis[aux+1]=true;
        aux+=1;
    }
    // se tiver quem for * e não foi marcado, "NO"
    for(auto u:ast){
        if(!vis[u]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}