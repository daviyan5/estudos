#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
   string matriz; 
   cin >> matriz;
   for(int i=0;i<matriz.size();i++){
       cout << matriz[i];
       if (matriz[i]-48>3) cout << "e" << endl;
   }

    
    
}