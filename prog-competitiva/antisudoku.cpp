#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    cin.ignore();
    while(t--){   
        vector<vector<int>> mat;
        mat.resize(9);
        for(int i=0;i<9;i++){
            mat[i].resize(9);
            for (int j = 0; j < 9; j++){
                char a; cin >> a;
                mat[i][j]=a-'0';
            }
            cin.ignore();
            
        }
        mat[0][0]=(mat[0][0]+1)%10;
		mat[1][3]=(mat[1][3]+1)%10;
		mat[2][6]=(mat[2][6]+1)%10;
		mat[3][1]=(mat[3][1]+1)%10;
		mat[4][4]=(mat[4][4]+1)%10;
		mat[5][7]=(mat[5][7]+1)%10;
		mat[6][2]=(mat[6][2]+1)%10;
		mat[7][5]=(mat[7][5]+1)%10;
		mat[8][8]=(mat[8][8]+1)%10;
        for(int i=0;i<9;i++){
            for (int j = 0; j < 9; j++){
                if(mat[i][j]==0) mat[i][j]++;
                cout << mat[i][j];
            }
            cout << endl;
            
        }
    }
}