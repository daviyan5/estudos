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

string s;
int n;
LL dp[10][2][2][81][81]; //pos start small impar par

int biton(int N, int pos) {return N = N | (1 << pos);}
int bitoff(int N, int pos) {return N = N & ~(1 << pos);}

LL solve(int pos, bool start, bool menor, int impar,int par){
    if(pos == n) {
        if(par - impar == 1) return 1;
        else return 0; // ops
    }
    if(dp[pos][start][menor][impar][par] != -1) return dp[pos][start][menor][impar][par]; //ja passei aqui
    LL ans = 0;
    int dig = s[pos] - '0';
    for(int i=0;i<10;i++){ //digitos possiveis 
        if(menor || i <= dig){ //se for já ou for menor agora
            bool nStart = (start && i==0); // true se for o começo
            bool nMenor = (menor || (i<dig));
            if(!nStart){ // numero não começa aqui
                if((n-pos-1) & 1) ans += solve(pos+1,false, nMenor,impar,par+i); //par
                else ans += solve(pos+1,false, nMenor,impar+i,par); //impar
            }
            else{ //numero começa aqui
                ans += solve(pos+1,true,nMenor,impar,par);
            }
        }
    }
    return dp[pos][start][menor][impar][par] = ans;
}
LL init(int N){
    if(N == 0) return 0;
    s = to_string(N);
    n = s.size();
    memset(dp,-1,sizeof(dp));
    LL ans = solve(0,true,false,0,0);
    return ans;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int a,b; cin >> a >> b;
        LL ans1 = init(b);
        LL ans2 = init(a-1);
        //cout << ans1 << " " << ans2 << " " << endl;
        cout << ans1-ans2 << endl;
    }
    return 0;
}