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
        priority_queue<pair<int,int>> pq;
        forc(i,n){
            int a; cin >> a;
            if(a>0) pq.push({a,i+1});
        }
        vector<vector<int>> talks;
        long ans = 0;
        
        while(pq.size() > 1){
            auto top = pq.top(); pq.pop();
            auto next = pq.top(); pq.pop();
            top.first -= next.first;
            ans += next.first;
            talks.pb({next.second,top.second,next.first});
            if(top.first) pq.push(top);
        }
        cout << ans << endl;
        for(auto &u:talks){
            for(int i=0;i<u[2];i++){
                cout << u[0] << " " << u[1] << endl;
            }
        }
    }
    return 0;
}