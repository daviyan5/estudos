#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define pb push_back
//#define endl '\n'
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

map<int,bool> dir;
int k; string s;
bool canWin(int team){
    //cout << s  << " time:  " << team << endl;
    int jogo = floor(team/2);
    int last = team%2;
    int res = s[jogo] == '?' ? last : s[jogo] - '0';
    if(res != last) return false;
    last = jogo%2;
    for(int i=1;i<k;i++){
        jogo = (1 << (k-1)) + floor(jogo/2);
        res  = s[jogo] == '?' ? dir[last] : s[jogo] - '0';
        //printf("jogo = %d, last = %d, res = %d, i = %d, team = %d\n",jogo,last,res,i,team);
        if(res != dir[last]) return false;
        else{
            last = dir[jogo];
        }
    }
    //cout << "END" << endl;
    return true;
}
int solve(){
    int ans = 0;
    forc(i,1 << (k)){
        if(canWin(i)) ans++;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    cin >> k;
    cin >> s;
    int q; cin >> q;
    bool pont = 0;
    forc(i,(1 << k)-1){
        dir[i] = pont;
        pont = !pont;
    }
    while(q--){
        int pos; char c;
        cin >> pos >> c;
        pos--;
        s[pos] = c;
        //cout << "START " << pos << " " << c << endl;
        cout << solve() << endl;
    }
    return 0;
}