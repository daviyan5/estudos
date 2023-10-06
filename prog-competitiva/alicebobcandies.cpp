#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        deque<int> d;
        for(int i=0;i<n;i++){
            int a; cin >> a;
            d.push_front(a);
        }
        int totalA=0,totalB=0,moves=0;
        int lastA=0,lastB=0;
        bool alice=true;
        while(!d.empty()){
            moves++;
            if(alice){
                lastA=0;
                while(lastA<=lastB && !d.empty()){
                    lastA+=d.back();
                    d.pop_back();
                }
                totalA+=lastA;
                alice=false;
            }
            else{
                lastB=0;
                while(lastB<=lastA && !d.empty()){
                    lastB+=d.front();
                    d.pop_front();
                }
                totalB+=lastB;
                alice=true;
            }
        }
        cout << moves << " " << totalA << " " << totalB << endl;
    }
}