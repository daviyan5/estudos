#include <iostream>
using namespace std;

int main(){
    int n,com=0,peg=0;
    cin >> n;
    char m,tabuleiro[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> m;
            tabuleiro[j][i]=m;

        }
        
    }
    for(int i=0;i<n;i++){
        if (i%2==0){
            for (int j = 0; j < n; j++){
                if (tabuleiro[j][i]=='o') peg++;
                if (peg>com) com=peg;
                if (tabuleiro[j][i]=='A') peg=0;
            }
        }
        else{
            for (int j = 0; j < n; j++){
                if (tabuleiro[n-j-1][i]=='o') peg++;
                if (peg>com) com=peg;
                if (tabuleiro[n-j-1][i]=='A') peg=0;
            }

        }

    }
    cout << com;

    

}