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
        vector<int> v;
        for(int i=0;i<n;i++){
            int a; cin >> a;
            v.push_back(a);
        }
        long long ans = 0;
        int l[3];
        int pont = 0;
        int sz = 0;
        bool meio = false;
        for(int i=0;i<n;i++){
            if(sz == 0){
                sz++; l[0] = v[i];
            }
            else if(sz == 1){
                sz++; l[1] = v[i];
            }
            else if(sz == 2){
                bool foi = false;
                if(l[0] > l[1]){
                    if(v[i] <= l[1]) foi = false;
                    else{
                        if(v[i] <= l[0]) meio = true;
                        sz++;
                        l[2] = v[i];
                        foi = true;
                    }
                }
                if(l[0] < l[1]){
                    if(v[i] >= l[1]) foi = false;
                    else{
                        if(v[i] >= l[0]) meio = true;
                        sz++;
                        l[2] = v[i];
                        foi = true;
                    }
                }
                if(!foi){
                    ans += (sz * (sz+1))/2;
                    sz = 0;
                    i--;
                }
            }
            else if(sz == 3){
                if(!meio){
                    int mx = max(l[0],max(l[1],l[2]));
                    int mn = min(l[0],min(l[1],l[2]));
                    if(v[i] < mx and v[i] > mn){
                        sz++; i++;
                    }
                }
                meio = false;
                ans += (sz * (sz+1))/2;
                sz = 0;
                i--;
            }
        }
        ans += (sz * (sz+1))/2;
        cout << ans << endl;
    }
    return 0;
}