#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int a; cin >> a;
            arr.push_back(a);
        }
        int count=0;
        for(int i=0;i<n-1;i++){
            if((float)max(arr[i],arr[i+1])/min(arr[i],arr[i+1])<=2) continue;
            else{
                int mi=min(arr[i],arr[i+1]);
                int ma=max(arr[i],arr[i+1]);
                while((float)ma/mi>2){
                    mi+=mi;
                    count++;
                }
            }
        }
        cout << count << endl;

    }
}