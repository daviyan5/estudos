#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
typedef long long int ll;


int main(){
   ll c,n,total=0;
   cin >> c >> n;
   priority_queue<ll,vector<ll>,greater<ll>> atend;
   for (ll i = 0;i <c;i++){
       atend.push(0);
   }
   for (ll i = 0; i < n; i++){
       ll x,y,t;
       cin >> x >> y;
       if(x>atend.top()){
           t=x+y;
           atend.pop();
           atend.push(t);
       }
       else{
           t=atend.top()+y;
           if (atend.top()-x > 20)  total++;
           atend.pop();
           atend.push(t);
       }
   }
   cout << total << endl;
}
