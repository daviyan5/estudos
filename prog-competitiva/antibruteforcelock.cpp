#include <bits/stdc++.h>
using namespace std;
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX=1e6 + 20;

int custo(string &a,string &b) {
	int w = 0;
	for (int i=0;i<4;i++){ //minimo de rolamentos
		w+=min(abs(a[i]-b[i]),10-abs(a[i]-b[i]));
    }
	return w;
}

int prim(vector<vector<ii>> &graf){
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	vector<bool> vis(graf.size());
	pq.push(mp(0,0));
	int c=0,ans=0;
	while(c<graf.size()){
		int u = pq.top().second, w = pq.top().first;
		pq.pop();
		if(!vis[u]){
			vis[u] = true;
			c++;
			ans+=w;
			for(int i=0;i<graf[u].size();i++){
				pq.push(mp(graf[u][i].second,graf[u][i].first));
            }
		}
	}
	return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<string> chaves(n);
		int inicial = inf;
        string inic="0000";
		for (int i=0;i<n;i++){
			cin >> chaves[i];
			inicial=min(inicial,custo(chaves[i],inic));
		}
		vector<vector<ii>> graf(n);
		for (int i=0;i<n;i++){ //custo pra transformar
			for (int j=i+1;j<n;j++){
				int w=custo(chaves[i],chaves[j]);
				graf[i].pb(mp(j,w)); 
				graf[j].pb(mp(i,w));
			}
        }
		cout << prim(graf)+inicial << endl;
	}
}