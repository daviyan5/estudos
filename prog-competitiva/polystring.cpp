#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        cin.ignore();
        string s;
        getline(cin,s);
        cout << s << endl;
        bool foi=false;
        int left=0;
        int right=0;
        short timer=5;
        while(timer--){
            printf("Timer=%d\n",timer);
            string s2020="2020";
            cout << "SubLeft:" << s.substr(0,timer) << endl;
            cout << "Sub20:" << s2020.substr(0,timer) << endl;
            if(s.substr(0,timer)==s2020.substr(0,timer) and timer>0){
                left=timer;
                cout << "Left: " <<left << endl;
                break;
            }
        }
        timer=5;
        while(timer--){
            printf("Timer=%d\n",timer);
            string s2020="2020";
            cout << "SubRight:" << s.substr(n-timer,timer) << endl;
            cout << "Sub20:" << s2020.substr(4-timer,timer) << endl;
            if(s.substr(n-timer,timer)==s2020.substr(4-timer,timer) and timer>0){
                right=timer;
                cout << "Right: " << right << endl;
                break;
            }
        }
        if(right+left<4) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    
}