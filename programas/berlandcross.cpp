#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
int u,r,d,l,n;
bool backtrack(vector<bool>& arr,int pos){
    if(pos==4){
        int ux=u,rx=r,dx=d,lx=l;
        if(arr[0]){
            if(ux>0 && lx>0){
                ux--;lx--;
            }
            else return false;
        }
        if(arr[1]){
            if(ux>0 && rx>0){
                ux--;rx--;
            }
            else return false;

        }
        if(arr[2]){
            if(rx>0 && dx>0){
                rx--;dx--;
            }
            else return false;
        }
        if(arr[3]){
            if(dx>0 && lx>0){
                dx--;lx--;
            }
            else return false;
        }
        if((ux>=0 && ux<=(n-2)) && (lx>=0 && lx<=(n-2)) && (rx>=0 && rx<=(n-2)) && (dx>=0 && dx<=(n-2))) return true;
        else return false;
    }
    int sem=backtrack(arr,pos+1);
    arr[pos]=true;
    int com=backtrack(arr,pos+1);
    arr[pos]=false;
    return (sem||com);

}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin >> n >> u >> r >> d >> l;
        vector<bool> arr(4,false);
        if(backtrack(arr,0)) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }
    return 0;
}