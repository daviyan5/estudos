#include <iostream>
using namespace std;

int main(){
    short m,n,cont,num=-1;
    bool esq=true,ok=true;
    cin >> n >> m;
    unsigned int matriz[m][n],el;
    for(int i=0;i<n;i++){
        esq=true;
        cont=0;
        for (int j = 0; j < m; j++){
            cin >> el;
            if(el==0 && esq){
                cont++;
            }
            else esq=false;

        }
        if(cont<=num and cont<m){
            ok = false;
        }
        num=cont;
    }
    if (ok) cout << 'S';
    else cout << 'N';
    return 0;
}