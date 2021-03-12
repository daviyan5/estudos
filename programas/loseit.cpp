#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> arr(6,0);
    for(int i=0;i<n;i++){
        int aux; cin >> aux;
        if(aux==4) aux=0;
        else if(aux==8) aux=1;
        else if(aux==15) aux=2;
        else if(aux==16) aux=3;
        else if(aux==23) aux=4;
        else if(aux==42) aux=5;
        if(aux==0 || arr[aux-1]>arr[aux]) arr[aux]++;
    }
    cout << n-6*arr[5] << endl;
}