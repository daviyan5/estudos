#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;
vector<bool> pin;
vector<bool> col;
int ans;
int mn,mx;
int n,m,h,w,q;

void bfs(int pos){
    queue<int> q;
    q.push(pos);
    pin[pos]=true;
    ans--;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        int c=top-m; if(c<0) c=0;
        int v=top+m; if(v>m*n-1) v=m*n-1;
        int d=top+1; if(d>m*n-1) d=m*n-1;
        int e=top-1; if(e<0) e=0;
        int arr[]={c,v,d,e};
        for(int i=0;i<4;i++){  
            int u=arr[i];
            if(!pin[u] && (u>=mn && u<=mx)){
                //cout << "U: " << u << endl;
                int a = floor(u/m) - floor(mn/m);
                int dw = mn+a*m;
                int up = dw + (w-1);
                //cout << "Dw: " << dw << " Up: " << up << " a: " << a << endl;
                if(u>=dw && u<=up){
                    if(dw==mn) col[u]=true;
                    pin[u]=true;
                    q.push(u);
                    ans--;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n >> m >> h >> w >> q;
    ans = n * m;
    pin.resize(n*m+1); col.resize(n*m+1);
    fill(pin.begin(),pin.end(),false);
    fill(col.begin(),col.end(),false);
    /*forc(i,n){
        forc(j,m){
            cout << i*m+j << " ";
        }
        cout << endl;
    }*/
    while(q--){
        int x,y; cin >> x >> y;
        x--; y--;
        int pos=x*m+y;
        //cout << "Pos: " << pos << endl;
        mn=pos;
        mx=pos+m*(h-1)+(w-1);
        bool foi=false;
        if(!col[pos]){
            col[pos]=true;
            for(int i=pos;i<=pos+m*(h-1);i+=m){ //provavelmente a bronca é aqui
                if(!pin[i]){
                    bfs(i);
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}