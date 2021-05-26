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

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n, m, k;
	cin >> n >> m >> k;
    int dp[80][80][80][80];
    int arr[n][m];
	forc(i, n){
        forc(j, m) {
		    cin >> arr[i][j];
        }
	}
	memset(dp,-inf,sizeof(dp));
	dp[0][0][0][0] = 0;
	forc(i, n){
        forc(j, m){
            forc(t, m / 2 + 1){
                forc(res, k) {
                    if (dp[i][j][t][res] == -inf) continue;
                    int pi = (j == m - 1 ? i + 1 : i);
                    int pj = (j == m - 1 ? 0 : j + 1);
                    if (i != pi) dp[pi][pj][0][res] = max(dp[pi][pj][0][res], dp[i][j][t][res]);
                    else dp[pi][pj][t][res] = max(dp[pi][pj][t][res], dp[i][j][t][res]);
                    if (t + 1 <= m / 2) { //adiciona mais um

                        int nrem = (res + arr[i][j]) % k;
                        if (i != pi) dp[pi][pj][0][nrem] = max(dp[pi][pj][0][nrem], dp[i][j][t][res] + arr[i][j]);
                        else dp[pi][pj][t + 1][nrem] = max(dp[pi][pj][t + 1][nrem], dp[i][j][t][res] + arr[i][j]);
                    
                    }
                }
            }
        }
	}
	
	cout << max(0, dp[n][0][0][0]) << endl;
	
	return 0;

}