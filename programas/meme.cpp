#include <iostream>
using namespace std;


int conc(long long int teste){
    int i=0;
    for(i=0;teste!=0;i++){
        teste=teste/10;
    }
    return i;
}



int main(){
    int n;
    cin >> n;
    for (int k = 0; k < n; k++){
        long long int i,j;
        cin >> i >> j;
        cout << (conc(j+1)-1)*i << endl;
    }
}

