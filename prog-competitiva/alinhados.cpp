#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double a,b;
bool zer=false;
void reta(pair<int,int> p1,pair<int,int> p2){
    if(p1.first-p2.first==0){
        zer=true;
        b=p1.first;
    }
    else{
        a=(float)(p1.second-p2.second)/(p1.first-p2.first);
        b=p1.second-p1.first*a;
        zer=false;
    };
}

int main() {
	int n;
    while(cin>>n){
        if (n==0) break;
        pair<int,int> fil[n];
        for (int i = 0; i < n; i++){
            int x=0,y=0;
            cin >> x >> y;
            fil[i].first=x;
            fil[i].second=y;
        }
        reta(fil[0],fil[1]);
        bool alim=true;
        if(!zer){
            for (int i = 2; i < n; i++){
                if(fil[i].first*a+b!=fil[i].second){
                alim=false;
                }
            }
        }
        else{
            for (int i = 2; i < n; i++){
                if(fil[i].first!=b){
                alim=false;
                }
            }
        }
        if (alim) cout << "ALINHADOS" << endl;
        else cout << "NAO_ALINHADOS" << endl;
    }
	return 0;
}