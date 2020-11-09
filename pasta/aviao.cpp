#include <iostream>
using namespace std;

int main()
{
    unsigned int a,d,n,m;
    cin >> n >> d >> a;
    if (d>=a)
    {
        m=d-a;
    }
    else
    {
        m=(n-a)+d;
    }
    cout << m;
}