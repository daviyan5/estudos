#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n,k; cin >> n >> k;
    deque<int> q;
    set<int> s;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        if(q.size()>=k){
            if(!s.count(a)){
                int front=q.front();
                q.pop_front();
                s.erase(s.find(front));
                q.push_back(a);
                s.insert(a);
            }
        }
        else{
            if(!s.count(a)){
                q.push_back(a);
                s.insert(a);
            }
        }
    }
    cout << q.size() << endl;
    while(!q.empty()){
        cout << q.back() << " ";
        q.pop_back();
    }
    
}