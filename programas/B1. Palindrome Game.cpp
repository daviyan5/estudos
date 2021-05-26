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

pair<int,int> palCount(string s){
    int i = 0;
    int j = s.size() - 1;
    int num = 0;
    int k = s.size()/2;
    while(i <= j){
        if(s[i] != s[j]){
            num++;
            k = i;
        }
        i++; j--;
    }
    return {num,k};
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; string s;
        cin >> n >> s;
        int numZeros = 0;
        int countA = 0;
        int countB = 0;
        for(auto u:s){
            if(u == '0') numZeros++;
        }
        bool alice = true,rev = false;
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
    return 0;
}