#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    while(true){
        int n; cin >> n;
        if(n==0) break;
        vector<int> h;
        for(int i=0;i<n;i++){
            int a; cin >> a;
            h.push_back(a);
        }
        stack<int>s;
        int ans = INT_MIN;
        h.push_back(-1);
        for(int i = 0; i < h.size(); i++) {
            while(!s.empty() && h[s.top()] > h[i]) {
                int top = s.top();
                s.pop();
                if(s.empty()) ans = max(ans, i*h[top]); // se todo mundo for menor
                else ans = max(ans, h[top]*(i-s.top()-1)); 
            }
            s.push(i);
        }
        cout << ans << endl;
    }
    return 0;
}