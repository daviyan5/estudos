#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define x first
#define y second

set<vector<int>> vis;
vector<int> solve(vector<int> &build,vector<vector<int>> &slot,vector<vector<int>> &banned){
    if(!binary_search(banned.begin(),banned.end(),build)) return build;
    else if(vis.count(build)) return {};
    else{
        int mx = INT_MIN;
        vector<int> ans = {};
        for(int i=0;i<build.size();i++){
            if(build[i] > 0){
                build[i]--;
                vector<int> aux = solve(build,slot,banned);
                int auxSum = 0; 
                for(int j=0;j<aux.size();j++){
                    auxSum += slot[j][aux[j]];
                }
                if(auxSum > mx and !aux.empty()){
                    mx = auxSum;
                    ans = aux;
                }
                build[i]++;
            }
        }
        vis.insert(build);
        return ans;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> slot(n);
    forc(i,n){
        int c; cin >> c;
        forc(j,c){
            int e; cin >> e;
            slot[i].push_back(e);
        }
    }
    int m; cin >> m;
    //vector<pair<int,int>> bannedSum;
    vector<vector<int>> banned(m,vector<int>(n));
    forc(i,m){
        //int sum = 0;
        forc(j,n){
            cin >> banned[i][j];
            banned[i][j]--;
            //sum += banned[i][j];
        }
        //bannedSum.push_back(mp(sum,i));
    }
    sort(banned.begin(),banned.end());
    vector<int> build;
    forc(i,n){
        build.push_back(slot[i].size() - 1); // para cada slot, o maior
    }
    vector<int> ans = solve(build,slot,banned);
    for(auto &u:ans) cout << u + 1 << " ";
    return 0;
}