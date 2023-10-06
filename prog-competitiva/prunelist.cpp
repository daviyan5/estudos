#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        priority_queue<int> fn,fm;
        for(int i=0;i<n;i++){
            int a; cin >> a;
            fn.push(a);
        }
        for(int i=0;i<m;i++){
            int a; cin >> a;
            fm.push(a);
        }
        int ans=0;
        while(!fn.empty() && !fm.empty()){
            if(fn.top()==fm.top()){
                fn.pop();
                fm.pop();
            }
            else if(fm.top()<fn.top()){
                while(!fn.empty() && fm.top()<fn.top()){
                    fn.pop(); ans++;
                }
            }
            else if(fn.top()<fm.top()){
                while(!fm.empty() && fn.top()<fm.top()){
                    fm.pop(); ans++;
                }
            }
        }
        while(!fn.empty()){
            ans++; fn.pop();
        }
        while(!fm.empty()){
            ans++; fm.pop();
        }
        cout << ans << endl;
    }
    return 0;
}