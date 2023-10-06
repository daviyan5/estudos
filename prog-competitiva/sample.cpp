    #include <bits/stdc++.h>
    using namespace std;
    using ll = int64_t;
    void chmax(ll& a, ll b){ if(a < b) a = b; }
     
    int main(){
        ll N, T;
        cin >> N >> T;
        vector<ll> A(N);
        for(ll& a : A) cin >> a;
        vector<ll> B{0}, C{0};
        for(ll a : A){
            for(ll i = B.size(); i--; ){
                B.push_back(B[i] + a);
            }
            swap(B, C);
        }
        sort(B.begin(), B.end(),greater<int>());
        
        ll ans = 0;
        for(ll x : C){
            if(x > T) continue;
            x += *lower_bound(B.begin(), B.end(), T - x, greater<int>());
            chmax(ans, x);
        }
        cout << ans << endl;
    }