#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main () {
    int n,c,m,xi,yi,j=0;
    set<int> carimbo,possui;
    cin >> n >> c >> m;
    for (int i = 0; i < c; i++){
        cin >> xi;
        carimbo.insert(xi);
        
    }
    for (int i = 0; i < m; i++){
        cin >> yi;
        if(carimbo.count(yi)>0){
            carimbo.erase(yi);
            j++;
        }
    }
    cout << c-j;

    
  
}