#include <iostream>
using namespace std;

int main()
{
    unsigned int t;
    cin >> t;
    t=t-3;
    if ((t%8-2)<4) cout << t%8-2 << endl;
    return 0;
}