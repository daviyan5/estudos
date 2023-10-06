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
    vector<int> a(n);
    forc(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    vector<int> aux(n);
    int j=0;
    for(int i=1;i<n;i+=2){
        aux[i]=a[j];
        j++;
    }
    for(int i=0;i<n;i+=2){
        aux[i]=a[j];
        j++;
    }
    int cont=0;
    for(int i=1;i<n-1;i++){
        if(aux[i]<aux[i-1] and aux[i]<aux[i+1]){
            cont++;
        }
    }
    cout << cont << endl;
    for(auto u:aux) cout << u << " ";
    cout << endl;
    return 0;
}