
#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 
  
int main() {
    int n;
    cin >> n;
    set<string> sufi[11],prefi[11];
    sufi[0].insert("");
    prefi[0].insert("");
    for(n;n>0;n--){
        string s; 
        cin >> s;
        for(int t=0;t<=10;t++){
            string pref = s.substr(0,t);
            if (sufi[t].count(pref)==0) continue;
            string suf = s.substr(t);
            if (prefi[10-t].count(suf)==0) continue;
            cout << s << endl;
            return 0;
        }
        for(int sz=1;sz<=10;sz++){
            string pref=s.substr(0,sz);
            string suf=s.substr(10-sz);
            prefi[sz].insert(pref);
            sufi[sz].insert(suf);
        }
    }
    cout << "ok"<< endl;

} 

