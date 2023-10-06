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
        vector<int> v(n);
        int mx = INT_MIN;
        int mn = INT_MAX;
        int mxId = 0;
        int mnId = 0;
        forc(i,n){
            cin >> v[i];
            if(v[i] > mx){
                mx = v[i];
                mxId = i;
            }
            if(v[i] < mn){
                mn = v[i];
                mnId = i;
            }
        }
        int i = min(mxId,mnId) + 1;
        int j = max(mxId,mnId) + 1;
        //printf("i = %d j = %d mxId = %d mnId = %d\n",i,j,mxId,mnId);
        cout << min(min(n+i-j+1,j),n-i+1) << endl;
    }
    return 0;
}