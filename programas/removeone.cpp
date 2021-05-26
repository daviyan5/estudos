#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX=2e5 + 20;
int arr[MX]; int dpl[MX]; int dpr[MX];
int n;
int dRight(int pos){
    if(pos==n-1) return 1;
    //cout << pos <<" "<< dpr[pos] << endl;
    if(arr[pos]<arr[pos+1]) dpr[pos] = dRight(pos+1) + 1;
    else dRight(pos+1);
    //cout << pos <<" "<< dpr[pos] << endl;
    return dpr[pos];
}
int dLeft(int pos){
    if(pos==0) return 1;
    //cout <<pos <<" "<<dpl[pos] << endl;
    if(arr[pos]>arr[pos-1]) dpl[pos] = dLeft(pos-1) + 1;
    else dLeft(pos-1);
    //cout <<pos <<" "<<dpl[pos] << endl;
    return dpl[pos];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n;
    forc(i,n){
        cin >> arr[i];
        dpr[i]=1; dpl[i]=1;
    }
    //cout << "right" << endl;
    dRight(0); 
    //cout << "left" << endl;
    dLeft(n-1);
    int ans=1;
    for(int i=0;i<n;i++){
        ans = max(ans,dpl[i]);
    }
    for(int i=0;i<n;i++){
        ans = max(ans,dpr[i]);
    }
    for(int i=1;i<n-1;i++){
        if(arr[i-1] < arr[i+1]){
            ans = max(ans,dpl[i-1]+dpr[i+1]);
        }
    }
    cout << ans << endl;
    return 0;
}