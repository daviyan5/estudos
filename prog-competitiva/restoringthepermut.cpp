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
        vector<int> q;
        forc(i,n){
            int a; cin >> a;
            q.pb(a);
        }
        vector<bool> visMi(n+1,false);
        for(auto u:q){
            if(!visMi[u]){
                cout << u << " ";
                visMi[u] = true;
            }
            else{ //acha o minimo não visitado
                int l = 1;
                int r = u-1;
                while(l<=r){
                    int m = (l+r)/2;
                    if(visMi[m]){
                        l = m + 1;
                    }
                    else{
                        r = m - 1;
                    }
                }
                cout << l << " ";
                visMi[l]=true;

            }
        }
        cout << endl;
        vector<bool> visMa(n+1,false);
        int prev = 0,at = 1;
        for(auto u:q){
            if(!visMa[u]){
                cout << u << " ";
                visMa[u] = true;
                prev = at;
                at = u;
            }
            else{ //acha o maximo não visitado
                int l = prev + 1;
                int r = u - 1;
                while(l<=r){
                    int m = (l+r)/2;
                    if(visMa[m]){
                        r = m - 1;
                    }
                    else{
                        l = m + 1;
                    }
                }
                cout << r << " ";
                visMa[r]=true;
            }
        }
        cout << endl;
    }
    return 0;
}