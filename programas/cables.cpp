#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> x; vector<int> pAux;
    map<int,int> ci; //ci -> dado a coordenada, devolve o indice, pi -> dado a pop, devolve a coordenada 
    vector<int> parent(n,0);
    int mx=INT_MIN;
    int mxi=0;
    for(int i=0;i<n;i++){
        int a; int b;
        cin >> a >> b;
        ci[a]=i;
        x.push_back(a);
        pAux.push_back(b);
        if(b>mx){
            mx=b;
            mxi=i;
        }
    }
    sort(x.begin(),x.end());
    vector<int> pR,pL; // dado o indice, da a população
    for(auto u: x){
        pR.push_back(pAux[ci[u]]);
    }
    pL=pR;
    reverse(pL.begin(),pL.end());
    parent[mxi]=-1;
    cout << "coordenadas" << endl;
    for(auto u:x) cout << u << " ";
    cout << endl;
    cout << "popDir" << endl;
    for(auto u:pR) cout << u << " ";
    cout << endl;
    cout << "popEsq" << endl;
    for(auto u:pL) cout << u << " ";
    cout << endl;
    for(int i=0;i<n;i++){
        int c=x[i];
        printf("pR[%d]=%d\n",i,pR[i]);
        if(parent[ci[c]]==-1) continue;
        int proc=i;
        int r=int(upper_bound(pR.begin()+proc,pR.end(),pR[i])-pR.begin());
        if(r==n) r=-1;
        proc=n-i-1;
        int l=int(upper_bound(pL.begin()+proc,pL.end(),pR[i])-pL.begin());
        if(l==n) l=-1;
        else l=(n-1-l);
        if(r==-1 || (l!=-1 && abs(x[r]-c)>abs(x[l]-c))){
            parent[ci[c]]=ci[x[l]]+1;
        }
        else if(l==-1 || (r!=-1 && abs(x[r]-c)<abs(x[l]-c))){
            parent[ci[c]]=ci[x[r]]+1;
        }
        else{
            if(pR[r]>pR[l]) parent[ci[c]]=ci[x[r]]+1;
            else parent[ci[c]]=ci[x[l]]+1;
        }
        printf("l = %d r = %d c = %d i = %d pR[%d]=%d pR[%d]=%d\n",l,r,c,i,r,pR[r],l,pR[l]);
    }
    for(auto u: parent) cout << u << " ";
    cout << endl;

    return 0;
}