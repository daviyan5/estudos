#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
int n;
vector<int> esq; vector<int> dir;
int ordem(vector<int> &dup,char o,int pos){
    if(o=='R'){
        return dir[pos];
    }
    if(o=='L'){
        return esq[pos];
    }
    if(o=='D'){
        int last = dup[pos];
        int k = min(last,pos);
        int j = max(last,pos);
        dir[esq[k]] = dir[j];
        esq[dir[j]] = esq[k];
        pos = dir[j];
		if(pos == n+1) pos = esq[pos];
        return pos;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int p,o; cin >> n >> o >> p;
    cin.ignore();
    string cb,op;
    getline(cin,cb); getline(cin,op);
    cb = 'S' + cb;
    esq.resize(n+1);
    dir.resize(n+1);
    dir[0]=1;
    for(int i=1;i<=n;i++){
        esq[i]=(i-1);
        dir[i]=(i+1);
    }
    vector<int> dup(n+1);
    stack<int> s;
    for(int i=1;i<=n;i++){
        if(cb[i]=='(') s.push(i);
        else{
            int j=s.top();
            dup[j]=i;
            dup[i]=j;
            s.pop();
        }
    }
    for(auto u:op){
        //printf("pos atual = %intd\n",p);
        p = ordem(dup,u,p);
    }
    for(int i=dir[0];i<=n;i=dir[i]) cout << cb[i];
    cout << endl;    
    return 0;
}