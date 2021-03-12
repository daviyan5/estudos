#include <bits/stdc++.h>
using namespace std;
#define endl '\n'



bool ganhou(char c,vector<string>& mat){
    cout << mat[0][0] << endl;
    cout << mat[1][0] << endl;
    cout << mat[2][0] << endl;
    for(int i=0;i<3;i++){
        if(mat[i][0]==c && mat[i][1]==c && mat[i][2]==c) return true;
    }
    for(int i=0;i<3;i++){
        if(mat[0][i]==c && mat[1][i]==c && mat[2][i]==c) return true;
    }
    if(mat[0][0]==c && mat[1][1]==c && mat[2][2]==c) return true;
    if(mat[0][2]==c && mat[1][1]==c && mat[2][0]==c) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    string num;
    getline(cin, num);
    int t;
    t = stoi(num);
    while(t--){
        vector<string> mat;
        int numX=0,numO=0;
        mat.resize(3);
        for(int i=0;i<3;i++){
            string a;
            getline(cin,a);
            mat.push_back(a);
            for(auto u:a){
                if(u=='X') numX++;
                if(u=='O') numO++;
            }
        }
        cin.ignore();
        if(numX!=numO && numX!=numO+1){
            cout << "no" << endl;
        }
        else{ 
            // se os dois ganharam, invalido
            //se O ganhou e numO!=numX, invalido
            //se X ganhou e numX!=numO+1, invalido
            bool ok=true;
            bool gX=ganhou('X',mat);
            bool gO=ganhou('O',mat);
            if(gX && gO) ok=false;
            if(gX && numX!=numO+1) ok=false;
            if(gO && numO!=numX) ok=false;
            if(!ok) cout << "no" << endl;
            else cout << "yes" << endl;
        }
        mat.clear();
    }
}