#include <iostream>
using namespace std;

int main(){
    short m,a,b,c;
    cin >> m >> a >> b;
    c=m-a-b;
    m = max(max(a,c),b);
    cout << m;
}