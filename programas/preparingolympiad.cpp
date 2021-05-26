#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define all(cc) (cc).begin(),(cc).end()
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX=1e6 + 20;

int biton(int N, int pos) {return N = N | (1 << pos);}
int bitoff(int N, int pos) {return N = N & ~(1 << pos);}
int N;
string binar(int mask){
    string aux="";
    while(mask>0){
        aux+= mask%2 +'0';
        mask/=2;
    }
    while(aux.size()<=N) aux+='0';
    reverse(aux.begin(),aux.end());
    return aux;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n,l,r,x; cin >> n >> l >> r >> x;
    N = n;
    vector<int> v;
    forc(i,n){
        int c; cin >> c;
        v.pb(c);
    }
    int ans = 0;
    forc(i,(1 << n)){
        int soma=0,total=0;
        int mn=INT_MAX, mx=INT_MIN;
        forc(j,n){
            bool ligado = (1 << j) & i;
            if(ligado){
                soma += v[j];
                total ++;
                mn = min(mn,v[j]);
                mx = max(mx,v[j]);

            }
        }
        if(total >= 2 && (soma >= l && soma <= r) && (mx-mn)>=x){
            cout << "Ligados: " << binar(i) << endl;
            ans++;
        }

    }
    cout << ans << endl;
    return 0;
}