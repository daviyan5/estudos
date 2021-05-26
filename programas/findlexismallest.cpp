#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define pb push_back
//#define endl '\n'
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX=1e6 + 20;

int root[MX];
map<int,priority_queue<int,vector<int>,greater<int>>> mis;
vector<int> v;
void build(int n){
    for(int i=0;i<n;i++){
        mis[i].push(v[i]);
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
        if(a < b) root[b] = a;
        else root[a] = b;
        while(!mis[b].empty()){
            mis[a].push(mis[b].top());
            mis[b].pop();
        }
        mis[b] = mis[a];
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        mis.clear(); v.clear();
        int n,m; cin >> n >> m;
        for(int i=0;i<n;i++){
            int a; cin >> a;
            v.pb(a);
        }
        build(n);
        for(int i=0;i<m;i++){
            int a,b; cin >> a >> b;
            a--; b--;
            join(a,b);
        }
        for(int i=0;i<n;i++){
            int pos = find(i);
            cout << mis[pos].top() << " ";
            mis[pos].pop();
        }
        cout << endl;

    }
    return 0;
}