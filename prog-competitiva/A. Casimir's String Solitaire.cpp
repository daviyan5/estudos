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

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int numA = 0,numB = 0,numC = 0;
        for(auto &u:s){
            if(u == 'A') numA++;
            else if (u == 'B') numB++;
            else numC++;
        }
        if(numB != numC + numA or s.size()%2) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}