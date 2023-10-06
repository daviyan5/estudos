#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    LL t; cin >> t;
    cin.ignore();
    while(t--){
        cin.ignore();
        set<LL> block; //trans bloqueados
        set<LL> X; //items em lock
        map<LL,set<LL>> mapa;
        while(true){ 
            char type;
            cin>>type;
            if(type=='#') break;
            LL tr,id;
            cin >> tr >> id;
            cin.ignore();
            //printf("TIPO: %c ID: %d TR: %d\n",type,id,tr);
            if(block.count(tr)) cout << "IGNORED" << endl;
            else if(type=='X' || X.count(id)){
                if(mapa.find(id)!=mapa.end() && (mapa[id].size() > 1 || !mapa[id].count(tr))){
                    cout << "DENIED" << endl;
                    block.insert(tr);
                }
                else{
                    cout << "GRANTED" << endl;
                    mapa[id].insert(tr);
                    if(type=='X') X.insert(id);
                }
            }
            else{
                cout << "GRANTED" << endl;
                mapa[id].insert(tr);
            }
        }
        if(t>0)cout << endl;
    }
    return 0;
}