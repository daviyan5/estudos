#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
int n;
int monta(int i, int j,int mn,vector<int>&arr) {
    if(j < i) return 0;
	int k = int(min_element(arr.begin()+i,arr.begin()+j+1)-arr.begin());
    return min(j-i+1,monta(i,k-1,arr[k],arr)+monta(k+1,j,arr[k],arr)+arr[k]-mn);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << monta(0,n-1,0,arr) << endl;
    return 0;
}