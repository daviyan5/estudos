#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    cout << "1000" << endl;
    string aux="";
    for(int i=0;i<50;i++){
        aux+='1';
    }
    for(int i=0;i<1000;i++){
        for(int i=0;i<50;i++){
            aux[i]='A'+rand()%3;
        }
        cout << aux << endl;
    }
    return 0;
}