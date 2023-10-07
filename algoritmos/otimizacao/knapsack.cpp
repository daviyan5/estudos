#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    int K; cin >> K;

    vector<int> v(n);
    vector<int> w(n);
    int dp[n+1][K+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < n; i++)
        cin >> v[i] >> w[i];

    for(int m = 1; m <= n; m++){
        for(int k = 1; k <= K; k++){
            if(w[m-1] <= k && v[m-1] + dp[m-1][k-w[m-1]] >= dp[m-1][k])
                dp[m][k] = v[m-1] + dp[m-1][k-w[m-1]];
            else
                dp[m][k] = dp[m-1][k];
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= K; j++){
            printf("%02d ", dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}
