#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;
vector<vector<int>> graf;


int bfs(int pos,int f){
    vector<bool> vis(64,false);
    map<int,int> dis;
    queue<int> q;
    dis[pos]=0; vis[pos]=true;
    q.push(pos);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        if(top == f){
            return dis[top];
        }
        else{
            for (auto u:graf[top]){
                if(!vis[u]){
                    vis[u]=true;
                    q.push(u);
                    dis[u]=dis[top]+1;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    graf.resize(64);
    forc(i,8){
        forc(j,8){
            int pos=i*8+j;
            //cout << pos << endl;
            int x,y;
            x=i-2; y=j-1; if(x>=0 && y>=0) graf[pos].push_back(x*8+y);
            //cout << x << " " << y << " " << x*8+y << endl;
            x=i-2; y=j+1; if(x>=0 && y<8) graf[pos].push_back(x*8+y);
            //cout << x << " " << y << " " << x*8+y << endl;
            x=i-1; y=j-2; if(x>=0 && y>=0) graf[pos].push_back(x*8+y);
            //cout << x << " " << y << " " << x*8+y << endl;
            x=i-1; y=j+2; if(x>=0 && y<8) graf[pos].push_back(x*8+y);
            //cout << x << " " << y << " " << x*8+y << endl;

            x=i+2; y=j-1; if(x<8 && y>=0) graf[pos].push_back(x*8+y);
            //cout << x << " " << y << " " << x*8+y << endl;
            x=i+2; y=j+1; if(x<8 && y<8) graf[pos].push_back(x*8+y);
            //cout << x << " " << y << " " << x*8+y << endl;
            x=i+1; y=j-2; if(x<8 && y>=0) graf[pos].push_back(x*8+y);
            //cout << x << " " << y << " " << x*8+y << endl;
            x=i+1; y=j+2; if(x<8 && y<8) graf[pos].push_back(x*8+y);
            //cout << x << " " << y << " " << x*8+y << endl;
            //cout << graf[pos].size() << endl;
        }
    }
    int t; cin >> t;
    while(t--){
        string i,f; cin >> i >> f;
        int yi=i[0]-'a';
        int xi=i[1]-'1';
        int yf=f[0]-'a';
        int xf=f[1]-'1';
        int posi=xi*8+yi;
        int posf=xf*8+yf;
        int ans=bfs(posi,posf);
        cout << ans << endl;
    }
    return 0;
}