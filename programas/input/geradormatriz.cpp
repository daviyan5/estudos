#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define endl '\n'
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    ofstream arq;
    arq.open("out.o");
    int a; cin >> a; srand(a);
    forc(i,1000){
        arq << rand()%1000 << " ";
    }
    arq << endl;
    forc(i,1000){
        arq << rand()%1000 << " " << rand()%1000 << endl;
    }
    return 0;
}