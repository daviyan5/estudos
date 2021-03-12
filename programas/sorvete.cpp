#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main () {
   int t,n,cont=0;
   cin >> t >> n;
   vector <pair<int,int>> inter(n);
   for (int i=0;i<n;i++){
      cin >> inter[i].first;
      cin >> inter[i].second;
   }
   sort(inter.begin(),inter.end());
   for(int i=0;i<n-1;i++){
      if (inter[i].first==-1) continue;
      for(int j=i+1;j<n;j++){
         if (inter[j].first==-1) continue;
         if (inter[j].first <= inter[i].second){
            if(inter[j].second >= inter[i].second){
               inter[i].second = inter [j].second;
            }
            inter[j].first=-1;
            inter[j].second=-1;
      }
     }
   }
   for (int i=0;i<n;i++){
      if (inter[i].first==-1) continue;
      cout << inter[i].first;
      cout <<" "<<inter[i].second<<endl;
   }


    
}