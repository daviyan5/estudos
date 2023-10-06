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
        vector<int> a(n),b(n);
        vector<int> pos(n + 1);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++){
            cin >> b[i];
            pos[b[i]/2] = i;
        }
        for(int i=n-1;i>=1;i--) pos[i] = min(pos[i],pos[i+1]);
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            int p = pos[(a[i] + 1)/2];
            ans = min(ans,i + p);
        }
        cout << ans << endl;
    }
    return 0;
}