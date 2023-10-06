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

int sumP(int n){
    int sum = 0;
    while(n%2 == 0){
        sum++;
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2){
        while (n % i == 0){
            sum++;
            n /= i;
        }
    }
    if(n > 2) sum++;
    return sum;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int a,b,k;
        cin >> a >> b >> k;
        if(b > a) swap(a,b);
        int mdc = __gcd(a,b);
        int p = a/mdc;
        int q = b/mdc;
        int numEx = sumP(p) + sumP(q);
        int numIg = 2 * sumP(mdc);
        bool ans = 0;
        int mx = numEx + numIg;
        if(a%b == 0 and a != b){
            ans = (mx >= k and k >= 1);
        }
        else{
            ans = (mx >= k and k >= 2);
        }
        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}