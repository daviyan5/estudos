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
    LL n,t; cin >> n >> t;
    vector<int> v(n);
    forc(i,n){
        cin >> v[i];
    }
    int ans = 0;
    LL sum = 0;
    int pos = -1;
    for(int i=0;i<n;i++){
        if(i!=0) sum-=v[i-1];
        if(pos+1<i){
            pos = i - 1;
            sum = 0;
        }
        int j;
        for(j = pos + 1;j < n;j++){
            if(sum+v[j]<=t){
                sum+=v[j];
                pos = j;
            }
            else break;
        }
        ans = max(ans,(j-i));
        if(ans >= n-i-1) break;
        //cout << sum << " " << ans << " " << i << " " << pos << endl;
    }
    cout << ans << endl;
    return 0;
}