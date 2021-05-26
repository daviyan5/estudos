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
        int n; string s;
        cin >> n >> s;
        map<char,bool> vis;
        char last = s[0];
        bool foi = true;
        for(int i=0;i<n;i++){
            if(s[i]!=last){
                if(vis[s[i]]){
                    foi = false;
                    break;
                }
                else{
                    vis[last] = true;
                    last = s[i];
                }
            }
        }
        if(foi) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}