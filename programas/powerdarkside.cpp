#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX=1e6 + 20;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    vector<LL> som(n),men(n),aux(n);
    forc(i,n){
        LL a,b,c; cin >> a >> b >> c;
        som[i]=a+b+c;
        men[i]=som[i]-max(max(a,b),c);
        aux[i]=men[i];
    }
    sort(aux.begin(),aux.end());
    forc(i,n){
        int pos=int(upper_bound(aux.begin(),aux.end(),som[i]-2)-aux.begin());
        //cout << i <<" "<< pos << " ";
        if(som[i]-men[i]>=2 && pos>0) pos--;
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}