#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main () {
    int n;
    cin >> n;
    char c;
    string s;
    for(int i=0;i<=n;i++){
        bool ok=true;
        stack<char> pare;
        getline(cin,s);
        if (s.size()==0) continue;
        for(int j=0;j<s.size();j++){
            if (s[j]=='{' or s[j]=='[' or s[j]=='('){
                pare.push(s[j]);
            }
            else{
                if (s[j]=='}') {
                    if(pare.empty()) ok=false;
                    else if(pare.top()=='{') pare.pop();
                    else ok=false;
                }
                else if (s[j]==']') {
                    if(pare.empty()) ok=false;
                    else if(pare.top()=='[') pare.pop();
                    else ok=false;
                    
                }
                else if (s[j]==')') {
                    if(pare.empty()) ok=false;
                    else if(pare.top()=='(') pare.pop();
                    else ok=false;
                }
            }
        }
        if (ok and pare.empty()) cout << 'S' << endl;
        else cout << 'N' << endl;
    }
}