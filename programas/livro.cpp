#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> val(2e5+10);
vector<int> vec(2e5+10);

int acha(int i,int root,int conta){
    if(vec[i]!=root){
        val[i]=acha(vec[i],root,conta+1);
        return val[i];
    }
    else{
        val[i]=conta;
        return conta;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int q; cin>>q;
    for (int j = 0; j < q; j++){
        int n; cin>>n;
        vec.resize(n+1);
        val.resize(n+1);
        for (int i = 1; i <= n; i++){
            cin >> vec[i];
            val[i]=0;
        }
        for (int i = 1; i <= n; i++){
            if(val[i]==0){
                acha(i,i,1);
            }
            cout << val[i] << " ";
        }
        cout << endl;
    }
}
/*
1 1 1 1 1 
3 3 3 
2 3 3 2 1 3 
1 
2 2 2 2 
4 4 4 1 4 
6
5
1 2 3 4 5
3
2 3 1
6
4 6 2 1 5 3
1
1
4
3 4 1 2
5
5 1 2 4 3

*/