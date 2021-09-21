#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    long t; cin >> t;
    int sum = 0;
    int i = 1;
    for(i = 1; sum < t; i++){
        sum += i;
    }
    printf("%d\n",i-1);
    return 0;
}