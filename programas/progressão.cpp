#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        //numero de razoes igual, maior sequencia de razoes
        int arr[n],total=1,maior=1,mInd=0;
        int razao[n-1];
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            if(i==0) continue;
            razao[i-1]=arr[i]-arr[i-1];
            int k = i-1;
            if(k>=1){
                if(razao[k]==razao[k-1]){
                    total++;
                }
                else{
                    total=1;
                }
                if(total>maior){
                    maior=total;
                    mInd=k;
                }
            }
        }
        printf("%d %d",mInd-maior+1,mInd+1);
    }
}