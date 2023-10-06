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
        vector<int> s(4);
        cin >> s[0] >> s[1] >> s[2] >> s[3];
        vector<int> aux = s;
        sort(all(aux));
        int mx  = aux[3];
        int mx1 = aux[2];
        pair<int,int> m1 = {max(s[0],s[1]),min(s[0],s[1])};
        pair<int,int> m2 = {max(s[2],s[3]),min(s[2],s[3])};
        pair<int,int> m3 = {mx,mx1};
        if(m1 != m3 and m2 != m3) cout << "YES" << endl;
        else cout << "NO" << endl;
        
        
    }
    return 0;
}