#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long LL;
typedef long double LD;
int n; string s;
bool check(vector<bool> vis, int pos, int cubo,vector<string>& cubos){
    if(vis[cubo]) return false;
    if(pos==s.size()) return true;
    vis[cubo]=true;
    vector<int> prox;
    for(int i=0;i<n;i++){
        for(auto u:cubos[i]){
            if(u==s[pos] && !vis[i]){
                prox.push_back(i);
            }
        }
    }
    bool foi=false;
    for(auto u:prox){
        if(check(vis,pos+1,u,cubos)){
            foi=true;
            break;
        }
    }
    return foi;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    cin >> s >> n;
    cin.ignore();
    vector<string> cubos(n);
    vector<char> first;
    for(int i=0;i<n;i++){
        getline(cin,cubos[i]);
        remove(cubos[i].begin(), cubos[i].end(), ' ');
        cubos[i].resize(6);
        for(int u=0;u<6;u++){
            if(cubos[i][u]==s[0]) first.push_back(i);
        }
    }
    bool foi=false;
    vector<bool> vis(n);
    for(auto u:first){
        fill(vis.begin(),vis.end(),false);
        if(check(vis,1,u,cubos)){
            foi = true;
            break;
        }
    }
    if(!foi) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}