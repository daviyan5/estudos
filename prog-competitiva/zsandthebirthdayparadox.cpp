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
const int MOD = 1e6 + 3;

LL legExp(LL n, LL p){
    LL ans = 0;
    for(LL i = p;i <= n; i *= p) ans += n/i;
    return ans;
}
LL fastExp(LL base, LL exp){
	LL ans = 1;
    while(exp){
		if(exp&1) ans = (ans*base)%MOD;
		base = (base*base)%MOD;
		exp>>=1;
	}
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    LL n,k; cin >> n >> k;
    if(n<=62 && k > 1LL<<n ){
        cout << "1" << " " << "1" << endl;
        return 0;
    }
    LL mdcExp = legExp(k-1,2); // log2 do mdc do numerador e do denominador
    LL mdc = fastExp(2,mdcExp);
    LL inverso = fastExp(mdc,MOD-2);
    LL den = (fastExp(fastExp(2,k-1),n)*inverso)%MOD;
    LL num; LL salva = 0;
    if(k>=MOD) num = 0;
    else{
        LL ans = 1;
        LL nAux = (fastExp(2,n)+MOD-1)%MOD;
        salva = nAux;
        LL kAux = k - 1;
        while(kAux>0){
            ans = (ans * nAux)%MOD;
            if(nAux == 0) break;
            nAux--; kAux--;
        }
        num = ans;
    }
    num = (num*inverso)%MOD;
    num = (den - num + MOD)%MOD;
    //printf("mdc = %lld mod = %lld inverso = %lld num = %lld den = %lld\n",mdc,salva,inverso,num,den);
    cout << num << " " << den << endl;
    return 0;
}