#include <bits/stdc++.h>
using namespace std;

#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define x first
#define y second
#define all(cc) (cc).begin(),(cc).end()
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; string s;
        cin >> n >> s;
        vector<int> ast;
        for(int i=0;i<s.size();i++){
            if(s[i] == '*') ast.push_back(i);
        }
        int sz = ast.size();
        if(sz == 0){
            cout << '0' << endl;
            continue;
        }
        //qnt de asteriscos na direita = sz - 1 - i
        //qnt de asteriscos na esquerda = i
        //distancia pro prox da direita = ast[i+1] - ast[i] - 1
        //distancia pro prox da esquerda = ast[i] - ast[i-1] - 1
        LL minEsq[sz],minDir[sz];
        minEsq[0] = 0;
        minDir[sz-1] = 0;
        for(int i=1;i<sz;i++){
            LL d = ast[i] - ast[i-1] - 1;
            minEsq[i] = d * i + minEsq[i-1];
            //cout << i << " "<< ast[i] << " "<<minEsq[i] << endl;
        }
        for(int i = sz-2;i>=0;i--){
            LL d = ast[i+1] - ast[i] - 1;
            minDir[i] = d * (sz-i-1) + minDir[i+1];
            //cout << i << " "<< ast[i] << " "<<minDir[i] << endl;
        }
        LL ans = n;
        for(int i=0;i<sz;i++){
            ans = min(ans,minEsq[i] + minDir[i]);
        }
        cout << ans << endl;
    }
    return 0;
}