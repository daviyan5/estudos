#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(3,0);
        for(int i=0;i<n;i++){
            int a; cin >> a;
            arr[a%3]++;
        }
        int media=arr[0]+arr[1]+arr[2];
        media/=3;
        int f1=arr[0]-media,f2=arr[1]-media,f3=arr[2]-media;
        int maior=max(f1,max(f2,f3));
        int cont1,cont2,cont3;
        cont1=3*f1+2*f2+f3;
        cont2=3*f2+2*f3+f1;
        cont3=3*f3+2*f1+f2;
        cout << min(cont1,min(cont2,cont3)) << endl;
        
    }
}