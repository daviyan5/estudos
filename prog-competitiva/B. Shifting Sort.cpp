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

struct Rot{
    int l,r,d;
    Rot(int i,int j,int k): l(i),r(j),d(k) {}
};
vector<Rot> v;
int merge(int l,int r,vector<int> &arr){
    for(int i=l;i<=r;i++){
        int mn = INT_MAX;
        int mx = INT_MIN;
        int mnidx = i;
        for(int j=i;j<=r;j++){
            if(arr[j] < mn){
                mn = min(arr[j],mn);
                mnidx = j;
            }
            mx = max(arr[j],mx);
            if((i == l or mn >= arr[i-1]) and (i == r or mx <= arr[i+1])){
                int shift = (mnidx - i);
                reverse(arr.begin() + i,arr.begin() + mnidx);
                reverse(arr.begin() + mnidx,arr.begin() + j);
                reverse(arr.begin()+i,arr.begin()+j);
                Rot a(i+1,j+1,shift);
                v.push_back(a);
                return shift;
            }
        }
    }
    return 0;
}
int solve(int l,int r,vector<int> &arr){
    if(l > r) return 0;
    else{
        int m = (l+r)/2;
        return solve(l,m-1,arr) + solve(m+1,r,arr) + merge(l,r,arr);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin >> arr[i];
        int ans = solve(0,n-1,arr);
        cout << ans << endl;
        for(auto &u:v){
            cout << u.l <<" "<< u.r << " " << u.d << endl;
        }
        v.clear();
    }
    return 0;
}