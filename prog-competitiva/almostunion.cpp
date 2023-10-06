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
const int MX=2e5 + 20;
LL root[MX],sz[MX],sum[MX];

void build(int n){
    for(int i=1,j=n+1;i<=n;i++,j++){
        root[i]=j;
        root[j]=j;
        sz[j]=1; 
        sum[j]=i;
    }
}

int find(int a){
    if(a == root[a]) return a;
    return root[a] = find(root[a]);
}

void move(int p,int q){
    int a = find(p);
    int b = find(q);
    if(a!=b){
        sz[b]++; sz[a]--;
        sum[b]+=p; sum[a]-=p;
        root[p]=b;
    }
}
 
void join(int a, int b){
    a =  find(a);
    b =  find(b);
    if(a != b){
        if(sz[a] < sz[b]) root[b]=a;
        else root[a] = b;
        sz[a]+=sz[b]; sum[a]+=sum[b];
        sz[b]=sz[a]; sum[b]=sum[a];
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n,m;
    while(cin >> n >> m){
        if(n<0 || m<0) break;
        build(n);
        while(m--){
            int ord; cin >> ord;
            if(ord==1){
                int p,q; cin >> p >> q;
                join(p,q);
            }
            if(ord==2){
                int p,q; cin >> p >> q;
                move(p,q);
                //int pos=int(lower_bound(qm[a].begin(),qm[a].end(),p)-qm[a].begin());
                //cout << "Operação 2 find: " << a <<" "<< p << " " << pos << endl;
                
            }
            if(ord==3){
                int p; cin >> p;
                int a =  find(p);
                //cout << "Operação 3 find: " << a <<" "<< p << endl;
                cout << sz[a] << " "<< sum[a] << endl;
                
            }
        }
    }
    return 0;
}