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

string s;
vector<int> v;
LL dp[90][10];

bool ramp(string num){
    int sz = num.size();
    for(int i = 1;i < sz;i++){
        if(num[i]<num[i-1]) return false;
    }
    return true;
}

LL solve(int pos,int pre,bool zero,bool menor){
    if(pos == -1) return 1;
    if(menor && !zero && dp[pos][pre]!=-1) return dp[pos][pre];
    LL ans = 0;
    int lim = !menor? v[pos] : 9;
    for(int i=0;i<=lim;i++){
        bool nMenor = (menor || i<lim);
        if(zero){
            if(i > 0) ans += solve(pos-1,i,false,nMenor);
            else ans += solve(pos-1, 0, true, nMenor);
        }
        else if(i>=pre){
            ans += solve(pos-1,i,false,nMenor);
        }
        //printf("i = %d ans = %d pos = %d zero = %d menor = %d pre = %d\n",i,ans,pos,zero,menor,pre);
    }
    if(!zero && menor) dp[pos][pre] = ans;
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    memset(dp,-1,sizeof(dp));
    while(t--){
        cin >> s;
        if(ramp(s)){
            v.clear();
            int sz = s.size();
            forc(i,sz){
                v.pb(s[i]-'0');
            }
            reverse(all(v));
            LL ans = solve(sz-1,0,false,false) - 1;
            cout << ans << endl;
        }
        else{
            cout << "-1" << endl;
        }
    }
    return 0;
}