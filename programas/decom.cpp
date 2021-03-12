#include <iostream>
using namespace std;

int main(){
   int t;
   cin >> t;
   for (int i = 1; i <= t; i++){
       int n,k;
       cin >> n;
       k=n*n-n+1;
       cout << "caso "<<i<<":";
       for (int j = 0; j < n; j++){
           cout <<" "<< k;
           k=k+2;
       }
       cout << endl;
   }
}