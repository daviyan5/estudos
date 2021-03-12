#include <iostream>
using namespace std;

int main(){
   int ia,ib,fa,fb,t=0;
   cin >> ia >> ib >> fa >> fb;
   if (ib!=fb){
       t++;
       if (ia==1) ia=0;
       else ia=1;
   }
   if (ia!=fa){
       t++;
   }
   cout << t;
   return 0;
}