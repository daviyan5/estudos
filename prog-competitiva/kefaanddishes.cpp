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

LL n,m,k;
LL s[19]; LL bonus[19][19]; LL dp[1<<19][19];

string binar(int mask){
    string aux="";
    while(mask>0){
        aux+= mask%2 +'0';
        mask/=2;
    }
    while(aux.size()<=n) aux+='0';
    reverse(aux.begin(),aux.end());
    return aux;
}

LL solve(LL mask,int pos){
    //string bin = binar(mask);
    //cout << "Começou " << bin << " pos = " << pos << endl;
    if(dp[mask][pos] != -1) return dp[mask][pos];
    for(LL i=1;i<=n;i++){
        //cout << "Entrou: " << bin << " i = " << i << " pos = " << pos << endl;
        if(((1<<(i-1) & mask) && i!=pos)){
            //cout << binar(mask) <<" " << i << endl;
            dp[mask][pos] = max(dp[mask][pos],solve(mask-(1<<(pos-1)),i) + bonus[i][pos] + s[pos]);
        }
    }
    //cout << "dp de " << binar(mask) << " " << mask << " quando o ultimo é " << pos << " é " << dp[mask][pos] << endl; 
    return dp[mask][pos];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n >> m >> k;
    memset(bonus,0,sizeof(bonus));
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
        cin >> s[i];
    }
    forc(i,k){
        int a,b;
        LL c; 
        cin >> a >> b >> c;
        bonus[a][b]=c;
    }
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        LL pos = 1<<(i-1);
        dp[pos][i]=s[i];
    }
    for(LL i=1;i<=n;i++){
        solve((1<<(n))-1,i);
    }
    LL ans=0;
    for(LL i=0; i <= (1<<n);i++){
        if(__builtin_popcount(i) == m){
			for (int k = 1; k <= n; k++) ans = max(ans, dp[i][k]);
		}
    }
    cout << ans << endl;
    return 0;
}