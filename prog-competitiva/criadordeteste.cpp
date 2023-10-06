#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    ofstream arq("./input/arq.txt");
    string criador="";
    for(int i=0;i<10000;i++){
        criador+='a'+rand()%26;
    }
    cout << criador << endl;
    arq << criador << endl;
    arq << 100000 << endl;
    for(int i=0;i<100000;i++){
        string go=criador;
        for(int i=0;i<10;i++){
            go[rand()%2000]='a'+rand()%26;
        }
        arq << go << endl;
    }
    return 0;
}