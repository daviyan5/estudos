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

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    LL matriz[n][n];
    forc(i,n){
        forc(j,n){
            cin >> matriz[i][j];
        }
    }
    int arr[n];
    arr[0] = sqrt((matriz[0][1]*matriz[0][2])/matriz[1][2]);
    for(int i=1;i<n;i++){
        arr[i] = matriz[i][0]/arr[0];
    }
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}