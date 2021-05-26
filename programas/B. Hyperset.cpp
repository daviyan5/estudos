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

string third(string &s1,string &s2,int k){
    string aux = "";
    forc(i,k){
        if(s1[i] == s2[i]){
            aux += s1[i];
        }
        else{
            string h = "";
            h += s1[i]; h += s2[i];
            if(h.find('S') == string::npos) aux += 'S';
            else if(h.find('E') == string::npos) aux += 'E';
            else aux += 'T';
        }
    }
    return aux;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n,k; cin >> n >> k;

    vector<string> v;
    map<string,int> m;

    forc(i,n){
        string s; cin >> s;
        m[s]++; v.pb(s);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            string t = third(v[i],v[j],k);
            ans += m[t];
            //cout << v[i] << " " << v[j] << endl;
            //cout << t << " " << ans << endl;
        }
    }
    cout << ans/3 << endl;
    return 0;
}