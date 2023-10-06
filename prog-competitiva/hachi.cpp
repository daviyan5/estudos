#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    string s;
    cin >> s;
    int sz=s.size();
    if(sz<3){
        if(stoi(s)%8==0){
            cout << "Yes" << endl;
            return 0;
        }
        reverse(s.begin(),s.end());
        if(stoi(s)%8==0){
            cout << "Yes" << endl;
            return 0;
        }
        cout << "No" << endl;
        return 0;
    }
    map<char,int> freq;
    for(auto u:s){
        freq[u]++;
    }
    for(int i=104;i<1000;i+=8){
        string aux=to_string(i);
        map<char,int> freqaux=freq;
        bool foi=true;
        for(auto v:aux){
            freqaux[v]--;
            if(freqaux[v]<0){
                foi=false;
                break;
            }
        }
        if(foi){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}