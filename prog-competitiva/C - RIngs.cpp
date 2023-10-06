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
        int n; cin >> n; 
        string s; cin >> s;
        int l1,l2,r1,r2;
        bool foi = false;
        for(int i=0;i<n and !foi;i++){
            if(s[i] == '0'){
                foi = true;
                if(i >= n/2){
                    l1 = 1; r1 = i + 1;
                    l2 = 1; r2 = i;
                }
                else{
                    l1 = i + 2; r1 = n;
                    l2 = i + 1; r2 = n;
                }
            }
        }
        if(!foi){
            l1 = 1; r1 = n-1;
            l2 = 2; r2 = n;
        }
        cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
    }
    return 0;
}