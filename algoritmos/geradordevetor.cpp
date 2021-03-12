#include <bits/stdc++.h>
using namespace std;
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    ofstream arq;
    cout << "Digite a seed" << endl;
    int seed; cin >> seed;
    cout << "Digite o numero" << endl;
    int n; cin >> n;
    arq.open("teste.in");
    srand(seed);
    arq << '1' << '\n';
    arq << n << '\n';
    forc(i,n){
        arq << rand() << " ";
    }
    arq << '\n';

    return 0;
}