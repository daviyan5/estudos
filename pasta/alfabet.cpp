#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main(){
    queue<char> alf;
    bool ok=true;
    set<char> jaf;
    string l1,l2="";
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++){
        if(i%2==0) getline(cin,l1);
        else getline(cin,l2);
        int j;
        for(j=0;j<min(l1.size(),l2.size());j++){
            if(i%2==0){
                if(l1[j]==l2[j]) continue;
                else{
                    alf.push(l1[j]);
                    if(jaf.count(l1[j])==1) ok=false;
                    jaf.insert(l1[j]);
                    break;
                }
            }
            else{
                if(l1[j]==l2[j]) continue;
                else{
                    alf.push(l2[j]);
                    if(jaf.count(l2[j])==1) ok=false;
                    jaf.insert(l1[j]);
                    break;
                }
            }
        }
        if(i==0){
            jaf.insert(l1[0]);
            alf.push(l1[0]);
        }
    }
    if(!ok){
        cout << "Impossible" << endl;
        return 0;
    }
    vector<char> letra;
    map<char,int> numer;
    letra.resize(26);
    letra[0]='a';
    numer[letra[0]]=0;
    for (int i = 1; i < 26; i++){
        letra[i]=letra[i-1]+1;
        numer[letra[i]]=i;
    }
    int q=alf.size();
    char a,b;
    for(int i=0;i<q;i++){
        b=a;
        a=alf.front();
        alf.pop();
        printf("a: %c b: %c\n",a,b);
        if(i==0) continue;
        if(numer[b]>numer[a]){
            printf("nA antes:%d nB antes:%d\n",numer[a],numer[b]);
            printf("lA antes:%c lB antes:%c\n",letra[numer[a]],letra[numer[b]]);
            int t=numer[a];
            char k=letra[numer[a]];
            letra[numer[a]]=letra[numer[b]];
            letra[numer[b]]=k;
            numer[a]=numer[b];
            numer[b]=t;
            printf("nA depois:%d nB depois:%d\n",numer[a],numer[b]);
            printf("lA depois:%c lB depois:%c\n",letra[numer[a]],letra[numer[b]]);
        }
    }
    for (int i = 0; i < 26; i++){
        cout << letra[i];
    }
}