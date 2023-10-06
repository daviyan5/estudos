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

int a,b,n;
string s;
LL dp[19][165][2];

int biton(int N, int pos) {return N = N | (1 << pos);}
int bitoff(int N, int pos) {return N = N & ~(1 << pos);}

LL solve(int pos, LL sum, bool menor){
    if(pos == n) return sum;
    if(dp[pos][sum][menor]!=-1) return dp[pos][sum][menor];
    LL ans = 0;
    int lim = (!menor)? s[pos]-'0' : 9;
    forc(digit,lim+1){
        bool nMenor = (menor || digit < lim);
        LL nSum = sum + digit;
        ans += solve(pos+1,nSum,nMenor);
    }
    return dp[pos][sum][menor] = ans;

}

LL getAns(int N){
    s = to_string(N);
    n = s.size();
    memset(dp,-1,sizeof(dp));
    return solve(0,0,false);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    while(true){
        cin >> a >> b;
        if(a== -1 || b == -1) break;
        cout << getAns(b) - getAns(a-1) << endl;
    }
    return 0;
}