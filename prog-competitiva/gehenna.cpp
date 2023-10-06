#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t,aux; cin >> t;
    aux=t;
    cin.ignore();
    pair<int,pair<string,string>> venc;
    venc.first=INT_MIN;
    vector<string> user,gang;
    while(t--){
        string aux1,aux2;
        cin >> aux1 >> aux2;
        user.push_back(aux1);
        gang.push_back(aux2);
    }
    t=aux;
    int i=0;
    while(i<t){
        int n,m; cin >> n >> m;
        cin.ignore();
        map<char,int> mapa;
        for(int i=0;i<n;i++){
            string a; getline(cin,a);
            for(int j=0;j<m;j++){
                mapa[a[j]]++;
            }
        }
        int pont=0;
        bool foi=true;
        while(foi){
            for(auto u:user[i]){
                if(mapa[u]<=0){
                    foi=false;
                    break;
                }
                mapa[u]--;
            }
            if(!foi) break;
            for(auto u:gang[i]){
                if(mapa[u]<=0){
                    foi=false;
                    break;
                }
                mapa[u]--;
            }
            if(!foi) break;
            pont++;
        }
        if(pont>venc.first){
            venc.first=pont;
            venc.second=make_pair(user[i],gang[i]);
        }
        i++;
    }

    cout << venc.second.first << " " << venc.second.second << endl;
    return 0;
}