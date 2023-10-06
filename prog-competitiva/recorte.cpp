#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> total(n+1,0);
        vector<queue<int>> pos(n+1);
        set<int> conj;
        priority_queue<int,vector<int>,greater<int>> filaF;
        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            pos[a].push(i);
            conj.insert(a);
        }
        for (auto u: conj){
            int at,last=-1;
            while(!pos[u].empty()){
                at=pos[u].front();
                pos[u].pop();
                if(at-last>1) total[u]++;
                if(pos[u].empty() && at!=n-1) total[u]++;
                last=at;
            }
            filaF.push(total[u]);
            printf("Total[%d]=%d\n",u,total[u]);
        }
        cout << filaF.top() << endl;
    }
}