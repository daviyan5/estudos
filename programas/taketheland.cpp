#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX=1e6 + 20;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n,m;
    while(cin >> n >> m){
        if(n==0 || m==0) break;
        int mat[n][m];
        forc(i,n){
            forc(j,m){
                cin >> mat[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int sum[m];
            memset(sum,0,sizeof(sum));
            for(int j=i;j<n;j++){
                int aux=0,larg=0,alt=j-i+1; //soma ate agr
                for(int k=0;k<m;k++){
                    sum[k]+=!mat[j][k];
                    if(aux != larg*alt){
                        larg=0; aux=0;
                    }
                    larg++;
                    aux+=sum[k];
                    if(aux==larg*alt){
                        ans = max(ans,aux);
                    }
                }
            }
        }
        cout << ans << endl;

    }
    return 0;
}