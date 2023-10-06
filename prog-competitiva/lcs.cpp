#include <bits/stdc++.h>
using namespace std;
 
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define pb push_back
//#define endl '\n'
#define x first
#define y second
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX=1e6 + 20;

void lcs(string s1, string s2){
    int m = s1.size();
    int n = s2.size();
    int arr[m+1][n+1];
    forc(i,m+1){
        arr[i][0]=0;
    }
    forc(i,n+1){
        arr[0][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1] == s2[j-1]){
                arr[i][j] = arr[i-1][j-1]+1;
            }
            else{
                arr[i][j] = max(arr[i][j-1],arr[i-1][j]);
            }
        }
    }
    cout << arr[m][n] << endl;
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    string s1,s2;
    while(getline(cin,s1) && getline(cin,s2)){
        lcs(s1,s2);
    }
    return 0;
}