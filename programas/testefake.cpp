#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


int main(){
    vector<char> bet;
    queue<char> alf;
    bet.resize(26);
    bet[0]=0;
    if('a'>bet[0]) bet[0]='a';
    cout << bet[0];
    alf.push(bet[0]);
    for (int i = 1; i < 26; i++){
        bet[i]=bet[i-1]+1;
        alf.push(bet[i]);
        cout << bet[i];
    }
    while(!alf.empty()) {
        cout<<alf.front();
        alf.pop();
    }

}