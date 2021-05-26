#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    int K; cin >> K;

    vector<int> v(n); vector<int> w(n);
    int dp[n+1][K+1];
    memset(dp,0,sizeof(dp));

    forc(i,n) cin >> v[i] >> w[i];

    for(int m=1;m<=n;m++){
        for(int k=1;k<=K;k++){
            if(w[m-1] <= k and v[m-1] + dp[m-1][k-w[m-1]] >= dp[m-1][k])
                dp[m][k] = v[m-1] + dp[m-1][k-w[m-1]];
                
            else dp[m][k] = dp[m-1][k];
        }
    }
    forc(i,n+1){
        forc(j,K+1){
            printf("%02d ",dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}