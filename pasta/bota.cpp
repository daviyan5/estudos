#include <iostream>
using namespace std;;

int main(){
    int t,n,m;
    char l;
    int vD[61],vE[61];
    for (int i=30;i<=60;i++){
        vD[i]=0;
        vE[i]=0;
    }
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> m >> l;
        if (l=='E') vE[m]++;
        else vD[m]++;
    }
    t=0;
    for (int i=30;i<=60;i++){
        if (vD[i]>vE[i]) t += vE[i];
        else t += vD[i];
    }
    cout << t << endl;
}