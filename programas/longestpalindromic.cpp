#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX=1e6 + 20;
string s;
int dp[1010][1010];
int maior(int i,int j){
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==j) return 1;
    if(s[i]!=s[j]) return dp[i][j]=max(maior(i+1,j),maior(i,j-1));
    else return dp[i][j]=maior(i+1,j-1)+2;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    cin.ignore();
    while(t--){
        getline(cin,s);
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        cout << maior(0,n-1) << endl;
    }
    return 0;
}