#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin.ignore();
        int n,m; cin >> n >> m; //n é o tamanho, m é a quantidade
        cin.ignore();
        vector<string> v;
        for(int i=0;i<m;i++){
            string aux;
            getline(cin,aux);
            v.push_back(aux);
        }
        vector<int> arr;
        for(auto u:v){
            int count=0;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(u[i]>u[j]) count++;
                }
            }
            //printf("Count=%d\n",count);
            arr.push_back(count);
        }
        vector<int> org=arr;
        sort(org.begin(),org.end());
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(arr[j]==org[i]){
                    cout << v[j] << endl;
                    arr[j]=-1;
                    break;
                }
            }
        }
        if(t>0) cout << endl;
    }
}