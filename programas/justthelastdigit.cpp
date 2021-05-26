#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define pb push_back
//#define endl '\n'
#define x first
#define y second
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX=1e6 + 20;
int dist[501][501];

void floyd(int n){
    for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			int aux = 0;
			for (int k=i+1;k<=j-1;k++){ //todos entre i e j
				aux+=dist[i][k]*dist[k][j];
			}
			if(dist[i][j]==(aux+1)%10) dist[i][j]=1;
            else dist[i][j]=0;
		}
	}
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    cin.ignore();
    forc(i,n){
        string s; getline(cin,s);
        forc(j,n){
            dist[i][j] = s[j]-'0';
        }
    }
    floyd(n);
    forc(i,n){
        forc(j,n){
            cout << dist[i][j];
        }
        cout << endl;
    }
    return 0;
}