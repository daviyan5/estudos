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
        set<int> conj;
        map<int,int> freq;
        forc(i,n){
            int a; cin >> a;
            if(!conj.count(a)) conj.insert(a);
            freq[a]++;
        }
        vector<ii> v;
        for(auto u:conj){
            v.pb({u,freq[u]});
        }
        sort(all(v));
        int ans = 0;
        int sz = v.size();
        for(int i=0;i<sz;i++){
            while(freq[v[i].x]>0){
                int j = i + 1;
                if(freq[v[j].x]==0) break;
                while(j<sz){
                    if(freq[v[j].x] == 0) break;
                    freq[v[j].x]--; freq[v[i].x]--;
                    ans += 2;
                    j++;
                }
            }
        }
        cout << n - ans << endl;
    }
    return 0;
}