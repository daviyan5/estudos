#include <iostream>
using namespace std;

int main(){
  long int n,p=1,m=1;
  cin >> n;
  long int list[n+1];
  for (int i = 1; i<=n; i++)
  {
     cin >> m;
     list[i]=m;
  }
  m=0;
  for (int i = 1; i <= n; i++)
  {
     if(list[i]==list[i-1]){
        m++;
        if(m>p) p=m;
     }
     else m=1;

  }
  cout << p;
  return 0;
}