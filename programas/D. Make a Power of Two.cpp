#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define x first
#define y second
#define all(cc) (cc).begin(),(cc).end()
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX=1e6 + 20;
int biton(int N, int pos) {return N = N | (1 << pos);}
int bitoff(int N, int pos) {return N = N & ~(1 << pos);}

vector<string> powers;
void init(){
    for(LL i = 1, j = 0; j < 63; i *= 2, j++){
        powers.push_back(to_string(i));
    }
}
int maxPref(string t,string s){
    int count = 0;

    for (int i = 0; i < t.size(); i++){
        if (count == s.size()) break;
        else if (t[i] == s[count]) count++;
    }
    //cout << "S: " << s << " T: " << t << " COUNT: " << count << endl;
    return count;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    init();
    while(t--){
        int n; cin >> n;
        string s = to_string(n);
        int ans = s.size() + 1;
        for(auto &u:powers){
            int pref = maxPref(s,u);
            int next = s.size() + u.size() - 2 * pref;
            //cout << "NEXT: " << next << endl;
            ans = min(ans,next);
        }
        cout << ans << endl;

    }
    return 0;
}