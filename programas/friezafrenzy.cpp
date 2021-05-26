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
int sz[MX], root[MX];

void build(int n){
    for(int i=0;i<n;i++){
        sz[i]=1;
        root[i]=i;
    }
}

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
    int n,m; cin >> n >> m;
    build(n);
    vector<ii> v(m+1);
    set<int> conj;
    stack<int> q;
    forc(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        v[i]=(mp(a,b));
        conj.insert(a); conj.insert(b);
    }
    forc(i,m){
        int a; cin >> a;
        a--;
        q.push(a);
    }
    vector<int> res;
    int ans=n;
    while(!q.empty()){
        int top=q.top();
        q.pop();
        int u=find(v[top].y);
        int w=find(v[top].x);
        join(v[top].x,v[top].y);
        res.pb(ans);
        if(w!=u){
            ans--;
        }
    }
    reverse(res.begin(),res.end());
    for(auto u:res) cout << u << endl;

    return 0;
}