#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define endl '\n'
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;

const int MX = 200002;
int sz[MX], root[MX];

int acha(int a){
    if(a == root[a]) return a;
    return root[a] = acha(root[a]);
}
int conta(int a){
    int pa = acha(a);
    return sz[pa];
}
void join(int a, int b){
    a = acha(a);
    b = acha(b);
    if(a != b){
        if(sz[a] < sz[b])
            root[b] = a;  
        else root[a] = b;
        sz[a] += sz[b];
        sz[b] = sz[a];
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    int cont=1;
    while(t--){
        cin.ignore();
        string s,aux; cin >> s;
        aux = s;
        int q; cin >> q;
        stack<ii> f;
        while(q--){
            int c,i;
            cin >> c >> i;
            f.push(mp(c,i));
            if(c==2){
                aux[i]='#';
            }
        }
        forc(i,s.size()){
            sz[i]=1; root[i]=i;
            if(i>=1 && aux[i]!='#' && aux[i]==aux[i-1]){
                join(i,i-1);
            }
            //cout << i <<" "<<sz[i] << endl;
        }
        vector<int> ans;
        while(!f.empty()){
            int c=f.top().first,i = f.top().second;
            f.pop();
            if(c==1){
                //cout << aux << endl;
                //cout << aux[i] << endl;
                //cout << conta(i) << endl;
                ans.push_back(conta(i));
            }
            if(c==2){
                aux[i]=s[i];
                if(i>0 && aux[i]==aux[i-1]){
                    join(i,i-1);
                }
                if(i<s.size()-1 && aux[i]==aux[i+1]){
                    join(i,i+1);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        cout << "Case " << cont << ":" << endl;
        for(auto u: ans){
            cout << u << endl;
        }
        cont ++ ;
    }
    return 0;
}