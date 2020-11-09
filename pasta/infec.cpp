#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
   int n,c;
   cin >> n >> c;
   set<int> infec;
   priority_queue < int,vector<int>,greater<int> > poss;
   for(int i=0;i<c;i++){
       int p,in;
       cin >> p >> in;
       poss.push(p);
       for (int j = 0; j < in; j++){
           int q;
           cin >> q;
           infec.insert(q);
       }
   }
   int sz=poss.size();
   for (int i = 0; i <sz ; i++){
       if (!infec.count(poss.top())) cout << poss.top() << endl;
       poss.pop();
   }
   return 0;
   

    
    
}