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
        int n,k; cin >> n >> k;
        string s;
        int primeiro=-1,ultimo=-1;

        forc(i,n){
            char a; cin >> a;
            s += a;
            if(a == '*' && primeiro == -1){
                primeiro = i;
            }
            else if(a == '*'){
                ultimo = i;
            }
        }
        int ans = 0;
        if(primeiro != -1) ans++;
        if(ultimo != -1) ans++;
        if(ans > 1){
            if(ultimo-primeiro > k){
                int dis = ultimo-primeiro;
                while(dis > k){
                    for(int i = ultimo - k; i < ultimo;i++){
                        if(s[i]=='*'){
                            ultimo = i;
                            ans++;
                        }
                    }
                    dis = ultimo - primeiro;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}