#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    string s;
    getline(cin,s);
    int len=s.size();
    stack<char> t;
    map<char,int> freq;
    for(auto u:s) freq[u]++;
    for(int i=0;i<len;i++){
        if(t.empty()){
            t.push(s[i]);
            freq[s[i]]--;
        }
        else{
            bool tem=false;
            for(int j='a';j<t.top();j++){
                if(freq[j]>0) tem=true;
            }
            if(!tem){
                cout << t.top();
                t.pop();
                i--;
            }
            else{
                t.push(s[i]);
                freq[s[i]]--;
            }
        }
    }
    while(!t.empty()){
        cout << t.top();
        t.pop();
    }
    cout << endl;
    return 0;
}