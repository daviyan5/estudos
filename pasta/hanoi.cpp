#include <iostream>
using namespace std;

long long int resultados[31];

int hanoi(int n){
	if (resultados[n]!=-1) return resultados[n];
	
    if (n==1) return 1;
    else return resultados[n]=2*hanoi(n-1)+1;
}
int main(){
   int d=-1,i=1;
   long long int total;
   for ( i = 1; i <= 30; i++)
   {
       resultados[i]=-1;
   }
   
   for(i=1;i==i and d!=0;i++)
   {
       cin >> d;
       if (d==0) break;
       else {
           total=hanoi(d);
           cout << "Teste " << i << endl << total << endl << endl;
       }

   }
   return 0;
}