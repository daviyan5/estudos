#include <iostream>
using namespace std;

int hanoi(int n){
	cout << n << endl;
    if (n==1) return 1;
    else n=2*hanoi(n-1)+1;
}
int main(){
   int d=-1,i=1;
   long long int total;
   while(cin >> d && d)
   {
	   total=hanoi(d);
	   cout << "Teste " << i << endl << total << endl << endl;
    
       i++;
   }
   return 0;
}