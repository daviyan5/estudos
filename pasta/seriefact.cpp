#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n,p;
    cin >> n;
    double r=0;
    for (int i = n; i > 0; i--){
        p=2^i - 1;
        r=1/p+(i+1)*r;
    }
    cout << r;
}