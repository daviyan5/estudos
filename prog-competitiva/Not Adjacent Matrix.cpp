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
void printa(vector<vector<int>> &matriz){
    int n = matriz.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}
void check(vector<vector<int>> &matriz){
    int n = matriz.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i > 0){
                int dif = abs(matriz[i][j] - matriz[i-1][j]);
                if(dif == 1){
                    cout << -1 << endl;
                    return;
                }
            }
            if(i < n-1){
                int dif = abs(matriz[i][j] - matriz[i+1][j]);
                if(dif == 1){
                    cout << -1 << endl;
                    return;
                }
            }
            if(j > 0){
                int dif = abs(matriz[i][j] - matriz[i][j-1]);
                if(dif == 1){
                    cout << -1 << endl;
                    return;
                }
            }
            if(j < n-1){
                int dif = abs(matriz[i][j] - matriz[i][j+1]);
                if(dif == 1){
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }
    printa(matriz);
}
void solve(int n){
    vector<vector<int>> matriz(n);
    int count = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //cout << count << endl;
            matriz[i].push_back(count);
            count += 2;
            if(count > n*n){
                count = 2;
            }
        }
    }
    check(matriz);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        solve(n);
    }
    return 0;
}