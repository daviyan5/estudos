#include <bits/stdc++.h> 
#include <iostream>
#include <stdio.h>
using namespace std; 
  
int main() {
    queue<char> times;
    for (int i=0;i<16;i++){
        char d='A';
        d=d+i;
        times.push(d);
    }
    for (int i=0;i<15;i++){
        int t1,t2;
        cin >> t1 >> t2;
        if (t1 >t2){
            t1=times.front();
            times.pop();
            times.pop();
            times.push(t1);
        }
        else{
            times.pop();
            t2=times.front();
            times.pop();
            times.push(t2);
        }
    }
    cout << times.front();
}

