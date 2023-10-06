#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<long long int>> mat(n);
    vector<long long int> linha(n);
    long long int somaT=0;
    for (int i = 0; i < n; i++){
        long long int somaL=0;
        mat[i].resize(n);
        for (int j = 0; j < n; j++){
            long long int a; cin >> a;
            somaL+=a;
            mat[i][j]=a;
        }
        linha[i]=somaL;
        somaT+=somaL;
    }
    somaT/=(n-1);
    for (int i = 0; i < n; i++){
        mat[i][i]=somaT-linha[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
    
}