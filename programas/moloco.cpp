#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long LL;
typedef long double LD;
vector<int> c;
vector<int> b;
int backtrack(vector<bool> &tem,int k,int pos){
    if(pos>6){
        int aux=0;
        for(auto u:b){
            if(tem[u] && k>=c[u]){
                k-=c[u];
                aux++;
            }
            //cout << u << " ";
        }
        //cout << endl;
        //for(auto u:tem) cout << u << " ";
        //cout << endl;
        //cout << aux << endl;
        return aux;
    }
    int sem = backtrack(tem,k,pos+1);
    tem[pos]=true;
    int com = backtrack(tem,k,pos+1);
    tem[pos]=false;
    return max(sem,com);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n,k; cin >> n >> k;
    c.resize(7); b.resize(n);
    for(int i=1;i<=6;i++){
        cin >> c[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    vector<bool> tem(7,false);
    int ans=backtrack(tem,k,1);
    cout << ans << endl;
    return 0;
}