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

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int res = (a-1) % 4;
        int resXor = res == 0? a-1 : res == 1? 1 : res == 2? a : 0;
        int next = b ^ resXor;
        //cout << res <<" " <<  resXor << " " << next << endl;
        if(resXor == b){
            cout << a << endl;
        }
        else if(next != a){
            cout << a + 1 << endl;
        }
        else{
            cout << a + 2 << endl;
        }
    }
    return 0;
}