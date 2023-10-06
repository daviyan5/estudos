#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp(a, b) make_pair(a, b)
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef pair<int,int> ii;
typedef long double LD;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    int aux=1;
    ofstream arq;
    arq.open("out1.in");
    while(t--){
        int n, cnt = 0; 
        cin >> n;
        vector<int> v(n); // 1 3 6 2 5 4
        forc(i, n) cin >> v[i];
        sort(v.begin(), v.end());

        int min_ = v[0];
        set<int> s;
        for(int i = 1; i*i <= min_; i++){
            if(min_ % i == 0){
                s.insert(i);
                s.insert(min_/i);
            }
        }

        for(auto e: s){
            int foi = true;
            for(auto x: v){
                if(x % e != 0){
                    foi = false;
                    break;
                }
            }
            if(foi) cnt++;
        }    
        
        arq << "Case #" << aux << ": " << cnt << endl;
        aux++;
        s.clear();
        v.clear();
    }
    return 0;
}

/*
3
4
1 2 3 5
4
4 4 6 8
8
40 88 32 40 48 32 40 24
*/