#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;
map<int,int> grauE;
vector<vector<int>> graf;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    graf.resize(n+1);
    forc(i,n){
        int a; cin >> a;
        if(a!=-1){
            grauE[i+1]++;
            graf[a].push_back(i+1);
        }
        else grauE[i+1]=0;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(grauE[i]==0){
            q.push(i);
        }
    }
    int ans=1;
    q.push(-1);
    while(!q.empty()){
        int top=q.front();
        q.pop();
        if(top==-1 && !q.empty()){
            ans++;
            q.push(-1);
        }
        else if(top == -1 && q.empty()) break;
        else{
            for(auto u:graf[top]){
                grauE[u]--;
                if(grauE[u]==0){
                    q.push(u);
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}