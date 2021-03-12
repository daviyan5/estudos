#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    double phi=(1+sqrt(5))/2;
    double phi2=(1-sqrt(5))/2;
    for(int i=0;i<n;i++){ 
        int a=(pow(phi,i)-pow(phi2,i))/sqrt(5);
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
