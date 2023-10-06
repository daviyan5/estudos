#include <iostream>
using namespace std;

int main(){
    int medalhas[3],tempos[3];
    cin >> tempos[0] >> tempos [1] >> tempos[2];
    for(int i=0; i<3;i++){
        if (max(max(tempos[0],tempos[1]),tempos[2])==tempos[i]) medalhas[2]=i+1;
        else if (min(min(tempos[0],tempos[1]),tempos[2])==tempos[i]) medalhas[0]=i+1;
        else medalhas[1]=i+1;
        
    }
    for (int i = 0; i < 3; i++)
    {
        cout << medalhas[i]<<endl;
    }
    return 0;
}

