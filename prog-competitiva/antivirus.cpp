#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp(a, b) make_pair(a, b)
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    int aux=1;
    ofstream arq;
    arq.open("out.in");
    while(t--){
        int tam;
        int mn = INT_MAX;
        int mId=0;
        forc(i,4){
            int a; cin >> a;
            if(a>mn){
                mn=a;
                mId=i;
            }
        }
        cin >> tam;
        cin.ignore();
        vector<string> v(4);
        forc(i, 4) getline(cin, v[i]);
        
        int ans[4] = {0};
        forc(i, mn-tam){
            bool foi = true;
            string s = v[mId].substr(i,tam);
            forc(i, 4){
                size_t pos = v[i].find(s);
                if(pos == string::npos){
                    foi = false;
                    break;
                }
                else{
                    ans[i] = (int)pos;
                }
            }
            if(foi) break;
        }
    
        arq << "Case #" << aux << ": ";
        forc(i,4) arq << ans[i] << " ";
        arq << endl;
        aux++;
    }
    return 0;
}
