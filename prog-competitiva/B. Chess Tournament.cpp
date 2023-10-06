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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<int> win;
        for(int i=0;i<n;i++){
            if(s[i] == '2'){
                win.push_back(i);
            }
        }
        char mat[n][n];
        memset(mat,'=',sizeof(mat));
        for(int i=0;i<n;i++) mat[i][i] = 'X';
        int m = win.size();
        if(m == 1 or m == 2){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            for(int i=0;i<m;i++){
                int j = (win[(i+1)%m]);
                mat[win[i]][j] = '+';
                mat[j][win[i]] = '-';
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout << mat[i][j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}