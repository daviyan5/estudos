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

pair<LL,pair<string,string>> count(string s){
    LL sum = 0;
    int n = s.size();
    for(int i = 0 ;i < n - 3;i++){
        string sub = s.substr(i,min(4,n));
        if(sub == "haha") sum++;
    }
    string pref = s.substr(0,min(3,n));
    string suf = s.substr(max(0,n-3),min(3,n));
    return {sum,{pref,suf}};
}
pair<LL,pair<string,string>> concat(pair<LL,pair<string,string>> suf,pair<LL,pair<string,string>> pref){
    LL sum = 0;
    sum += suf.first + pref.first;
    auto v = count(suf.second.second + pref.second.first);
    sum += v.first;
    string s = suf.second.first + pref.second.second;
    int n = s.size();
    string nPref = s.substr(0,min(3,n));
    string nSuf = s.substr(max(0,n-3),min(3,n));
    return {sum,{nPref,nSuf}};

}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<string,pair<LL,pair<string,string>>> m;
        string var;
        forc(i,n){
            string op;
            cin >> var >> op;
            if(op == ":="){
                string s;
                cin >> s;
                m[var] = count(s);
            }
            else{
                string var1,op1,var2;
                cin >> var1 >> op1 >> var2;
                m[var] = concat(m[var1],m[var2]);
            }

        }
        cout << m[var].first << endl;
    }
    return 0;
}