#include <bits/stdc++.h> 
#include <iostream>
#include <stdio.h>
using namespace std; 
  
int main() {
    set <int> a,b;
    int na,nb,total=0;
    cin >> na >> nb;
    for (int i = 0; i < na; i++){
        int xa;
        cin >> xa;
        a.insert(xa);
    }
    for (int i = 0; i < nb; i++){
        int xb;
        cin >> xb;
        b.insert(xb);
    }
    if (a.size()>b.size()){
        for (int i = 0; i < b.size(); i++){
            auto c= b.begin();
            advance(c,i);
            if(!a.count(*c)) total++;
        }
    }
    else{
        for (int i = 0; i < a.size(); i++){
            auto c= a.begin();
            advance(c,i);
            if(!b.count(*c)) total++;
        }
    }
    cout << total<<endl;
}

