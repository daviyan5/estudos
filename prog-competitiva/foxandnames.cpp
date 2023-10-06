#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int q; cin >> q; cin.ignore();
    vector<set<int>> grafo(26);
    vector<int> grauEntrada(26,0);
    string s[q];
    for (int i = 0; i < q; i++){
        getline(cin,s[i]);
    }
    for (int i = 0; i < q; i++){
        for(int k = i+1; k < q; k++){

            int sa=s[i].length(); int sb=s[k].length();
            int size=sb>sa?sa:sb;
            bool diff=false;
            for (int j = 0; j < size; j++){
                int c1=s[i][j]-'a'; int c2=s[k][j]-'a';
                if(c1==c2) continue;
                else{
                    if(!grafo[c1].count(c2)){
                        grafo[c1].insert(c2);
                        grauEntrada[c2]++;
                        diff=true;
                    }
                    break;
                }
            }
            if(!diff){
                if(sa>sb){
                    cout << "Impossible" << endl;
                    return 0;
                }
            }
        }
    }
    queue<int> filaF;
    for (int i = 0; i < q; i++){
        if(grauEntrada[i]==0){
            filaF.push(i);
        }
    }
    string alfa="";
    while(!filaF.empty()){
        char on = filaF.front();
        filaF.pop();
        alfa += on+'a';
        for(auto u: grafo[on]){
            grauEntrada[u]--;
            if(grauEntrada[u]==0) filaF.push(u);
        }
    }
    if(alfa.size()!=26){
        cout << "Impossible" << endl;
        return 0;
    }
    cout << alfa << endl;
    
}