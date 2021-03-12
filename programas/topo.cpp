#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> arr(n+1);
    vector<int> grau(n+1,0);
    for (int i = 0; i < m; i++){
        int a,b;
        //b depende de a
        cin >> a >> b;
        arr[a].push_back(b);
        grau[b]++;
    }
    priority_queue<int,vector<int>,greater<int>> sol;
    int tot=0;
    for (int i = 1; i <= n; i++){
        if(grau[i]==0){
            sol.push(i);
        }
        sort(arr[i].begin(),arr[i].end());
    }
    queue<int> filaF;
    while(!sol.empty()){
        int at=sol.top();
        filaF.push(at);
        tot++;
        sol.pop();
        for(auto prox: arr[at]){
            grau[prox]--;
            if(grau[prox]==0){
                sol.push(prox);
            }
        }

    }
    if(tot!=n){
        cout << "Sandro fails." << endl;
    }
    else{
        for (int i = 1; i <= n; i++){
            cout << filaF.front() << " ";
            filaF.pop();
        }
    }

}