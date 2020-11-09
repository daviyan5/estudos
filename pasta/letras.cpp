#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main(){
    char por;
    long long int count1=0,count2=0;
    string s;
    cin >> por;
    cin.ignore();
    getline(cin,s);
    istringstream ss(s);
    do{
        string word;
        ss >> word;
        if(word.find(por)==string::npos) count2++;
        else{
            count1++;
            count2++;
        }
    } while (ss);
    count2--;
    float f=(float)count1/count2;
    printf("%.1f",100*f);
}