#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    string linha;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> arr;
    map<int,int> per;
    while(true){
        int id,tempo;
        cin >> linha;
        if(linha=="#") break;
        cin >> id >> tempo;
        cin.ignore();
        arr.push(make_pair(tempo,id));
        per[id]=tempo;
    }
    int t; cin >> t;
    while(t--){
        pair<int,int> aux=arr.top();
        arr.pop();
        cout << aux.second << endl;
        aux.first+=per[aux.second];
        arr.push(aux);
    }
    
}