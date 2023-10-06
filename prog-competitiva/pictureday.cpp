#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    priority_queue<pair<int,int>> f;
    for(int i=0;i<n/2;i++){
        int a; cin >> a;
        int b; cin >> b;
        f.push(make_pair(max(a,b),min(a,b)));
    }
    deque<int> d;
    while(!f.empty()){
        pair<int,int> top=f.top();
        f.pop();
        int maior=top.first;
        int menor=top.second;
        if(d.empty()){
            d.push_back(maior);
            d.push_back(menor);
        }
        else{
            if(maior<d.back() && maior>d.front()){
                d.push_back(maior);
                d.push_back(menor);
            }
            else if(maior<d.front() && maior>d.back()){
                d.push_front(maior);
                d.push_front(menor);
            }
            else{
                int absF=d.front()-maior;
                int absB=d.back()-maior;
                if(absB<0 && absF<0){
                    cout << -1 << endl;
                    return 0;
                }
                else if(absF>absB && absB>0){
                    d.push_back(maior);
                    d.push_back(menor);
                }
                else{
                    d.push_front(maior);
                    d.push_front(menor);
                }
            }
            
        }


    }
    while(!d.empty()){
        cout << d.back() << " ";
        d.pop_back();
    }
    cout << endl;
    return 0;
}