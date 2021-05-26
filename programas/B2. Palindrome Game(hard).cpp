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

bool isPal(string s){
    int i = 0, j = s.size()-1;
    while(i <= j){
        if(s[i] != s[j]) return false;

        i++; j--;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; string s;
        cin >> n >> s;
        bool pal = isPal(s);
        if(pal){
            int numZeros = 0;
            int countA = 0; int countB = 0;
            bool rev = false, alice = true;
            for(auto u:s){
                if(u == '0') numZeros++;
            }
            if(n % 2 == 1 and numZeros%2 == 1){
            countA++; numZeros--;
            alice = false;
            }
            while(numZeros > 0){
                if(numZeros%2 == 0) rev = false;
                if(alice){
                    if(!rev or numZeros >= 3){
                        countA++; numZeros--;
                        rev = true;
                    }
                    else rev = false;
                    alice = false;
                }
                else{
                    if(!rev or numZeros >= 3){
                        countB++; numZeros--;
                        rev = true;
                    }
                    else rev = false;
                    alice = true;
                }
            }
            if(countA < countB) cout << "ALICE" << endl;
            else if(countB < countA) cout << "BOB" << endl;
            else cout << "DRAW" << endl;
        }
        else{
            int numZeros = 0, numUm = 0;
            for(auto u:s) if(u == '0') numZeros++;
            for(int i = 0; i < n/2;i++){
                if((s[i] == '1' or s[n-i-1] == '1') and s[i]!=s[n-i-1]) numUm++;
            }
            if(numZeros == 2 and numUm == 1) cout << "DRAW" << endl;
            else cout << "ALICE" << endl;
        }
    }
    return 0;
}