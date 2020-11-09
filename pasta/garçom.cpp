#include <iostream>
using namespace std;

int main(){
  short l,c,n,caiu=0;
  cin >> n;
  for(int i=0;i<n;i++){
      cin >> l >> c;
      if (l>c) caiu = caiu + c;
  }
  cout << caiu;

  return 0;
}