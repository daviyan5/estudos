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
const int MOD = 1e6;
LL n,k,l;
struct Matriz{
    LL mat[2][2];
    Matriz operator * (const Matriz &p) {
        Matriz ans;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                ans.mat[i][j] = 0;
                for(int k = 0; k < 2; k++){
                    ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * p.mat[k][j]) % MOD;
                }
            }
        }
        return ans;
    }
};
void printa(Matriz a){
    cout << endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout << a.mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void fastExp(Matriz &base1,Matriz &base2,LL exp){
    while(exp){
        if(exp & 1) base1 = base1 * base2;
        base2 = base2 * base2;
        exp >>= 1;
        printa(base1);
        printa(base2);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n >> k >> l;
    k = k%MOD; l = l%MOD;
    Matriz a,b;
    b.mat[0][0] = k; b.mat[0][1] = 1;
    b.mat[1][0] = l; b.mat[1][1] = 0;
    n = n/5;
    if(n==1) printf("%06lld\n",k); //so um mini onibus
    else if(n==2) printf("%06lld\n",(k*k+l)%MOD); // 1 onibus ou 2 minionibus.
    else{
        a.mat[0][0] = (k*k+l)%MOD; // 2 minionibus
        a.mat[0][1] = k; //1 onibus
        a.mat[1][0] = 0; a.mat[1][1] = 0;
        printa(a); printa(b);
        fastExp(a,b,n-2); 
        printf("%06lld\n",a.mat[0][0]%MOD);
    }

    return 0;
}