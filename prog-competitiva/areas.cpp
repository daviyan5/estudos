#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n);
        set<int> areas;
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                int area=abs(arr[i]-arr[j]);
                cout << area << endl;
                printf("arr[%d]=%d arr[%d]=%d area=%d\n",i,arr[i],j,arr[j],area);
                if(area>0) areas.insert(area);
            }
        }
        cout << areas.size() << endl;
        
    }
}