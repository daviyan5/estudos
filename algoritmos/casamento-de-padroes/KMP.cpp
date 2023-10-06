#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> init_next(string &padrao){
    int len = 0;
    int m = padrao.size();
    vector<int> next(m);
    next[0] = 0;
    int i = 1;
    while (i < m) {
        if(padrao[i] == padrao[len]) {
            len++;
            next[i] = len;
            i++;
        }
        else{
            if(len != 0) len = next[len - 1];
            else{
                next[i] = 0;
                i++;
            }
        }
    }
    return next;
}
vector<int> kmp(string &texto,string &padrao){
    vector<int> ans;
    vector<int> next = init_next(padrao);
    int n = texto.size(),m = padrao.size();
    int i = 0,j = 0;
    while(i <= n - m){
        while(j < m and padrao[j] == texto[i+j]){
            j += 1;
        }
        if(j == m){
            ans.push_back(i);
        }
        if(j == 0) i++;
        else{
            i += (j - next[j]);
            j = next[j];
        }
    }
    return ans;
}

int main(){
    string texto = "abracadabrabracadabrabrbracadbracadabrababcabbrabcabrabcabrabcadabraabaabracadabracabrabcabrabcabrabca";
    string padrao = "abracadabra";
    vector<int> ans = kmp(texto,padrao);
    for(auto &u:ans){
        cout << "Padrão encontrado no indice " << u << endl;
        for(int i = u; i < u + padrao.size();i++){
            if(texto[i] != padrao[i-u]) cout << "Erro!" << endl;
        }
        cout << "Correto!" << endl;
    }
    return 0;
}