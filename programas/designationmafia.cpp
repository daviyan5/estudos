#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define endl '\n'
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;



void floyd(int n,vector<vector<int>>& custo){
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                custo[i][j] = min(custo[i][j], custo[i][k] + custo[k][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    vector<vector<int>> custo(26);
    for(int i=0;i<26;i++){
        custo[i].resize(26);
        for(int j=0;j<26;j++){
            cin >> custo[i][j];
        }
        custo[i][i]=0;
    }
    floyd(26,custo);
    string s; cin >> s;
    LL ans=0;
    int sz=s.size();
    for(int i = 0; i<sz/2;i++){
        int mn=INT_MAX;
        int c1 = s[i]-'a';
        int c2 = s[sz-i-1]-'a';
        for(int j=0;j<26;j++){
            if(mn>custo[c1][j] + custo[c2][j]){
                mn = custo[c1][j] + custo[c2][j];
            }
        }
        ans+=mn;
    }
    cout << ans << endl;
    
    return 0;
}