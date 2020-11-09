#include <bits/stdc++.h> 
#include <iostream>
#include <stdio.h>
using namespace std; 
  
int main() {
    int colch=0,n;
    char frase;
    bool ok=true;
    cin >> n;
    for (int i = 0; i <= n; i=i){
        frase=getchar();
        if (frase=='}') colch--;
        else if (frase=='{') colch++;
        if (colch<0) ok=false;
        if (frase=='\n') i++;
    }
    if (colch!=0 or !ok) cout << 'N';
    else cout << 'S';
}

