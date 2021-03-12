#include <bits/stdc++.h> 
#include <iostream>
#include <stdio.h>
using namespace std; 



void traduc(long long int m,long long int n){
    map <string,string> dic;
    string jp,pt;
    cin.ignore();
    for (long long int i = 0; i < m; i++){
        getline(cin,jp);
        getline(cin,pt);
        dic[jp]=pt;
    }
    for (int i = 0; i < n; i++){
        string frase="oi";
        bool pri=true;
        getline(cin,frase);
        istringstream str(frase);
        do{
            string word;
            str >> word;
            if(pri){
                if (dic[word]=="") cout << word ;
                else cout << dic[word];
            }
            else if (dic[word]=="") cout << ' '<< word ;
            else cout << ' '<< dic[word];
            pri=false;
        } while(str);
        cout << endl;
    }
}


int main() {
    long long int t,m,n;
    cin >> t;
    for (long long int i = 0; i < t; i++){
        cin >> m >> n;
        traduc(m,n);
        cout << endl;
    }   
}