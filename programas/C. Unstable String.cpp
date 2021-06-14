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
const int MX=2e5 + 20;
int biton(int N, int pos) {return N = N | (1 << pos);}
int bitoff(int N, int pos) {return N = N & ~(1 << pos);}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size();
        bool tipo1 = !(s[0] == '?' or s[0] =='1'); // 0 par
        bool tipo2 = !(s[0] == '?' or s[0] =='0'); // 0 impar
        bool notipo = (s[0] == '?');
        LL ans  = 0;
        int tot = 0;
        int interr = 0;
        for(int i=0;i < n;i++){
            if(notipo){
                if(s[i]!='?'){
                    if(s[i] == '0'){
                        if(i%2 == 0) tipo1 = true;
                        else tipo2 = true;
                    }
                    else{
                        if(i%2 == 0) tipo2 = true;
                        else tipo1 = true;
                    }
                    notipo = false;
                }
            }
            else if(tipo1){
                if((i%2 == 1 and s[i] == '0') or (i%2 == 0 and s[i] == '1')){ //problema
                    tot = interr;
                    tipo1 = false;
                    tipo2 = true;
                }
            }
            else{
                if((i%2 == 1 and s[i] == '1') or (i%2 == 0 and s[i] == '0')){ //problema 
                    tot = interr;
                    tipo2 = false;
                    tipo1 = true;
                }
            }
            ans += (tot+1);
            if(s[i] == '?') interr++;
            else interr = 0;
            tot++;

        }
        cout << ans << endl;
    }
    return 0;
}