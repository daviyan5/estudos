#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> primos;
deque<long long int> divisores;
int tmax=-1; int imax=0;
void achaPrimos(long long int n){
    primos.clear();
    long long int tamanho=10*sqrt(n);
    printf("Tamanho=%lld e n=%lld\n",tamanho,n);
    vector<bool> ePrimo(tamanho,true);
    ePrimo[0]=false;
    ePrimo[1]=false;
    tmax=-1; imax=0;
    divisores.clear();
    int tamanhoR=0; 
    int total=0; int count=0;
    for (int i = 2; i < tamanho; i++){
        if(ePrimo[i]){
            while(n%i==0){
                n=n/i;
                divisores.push_back(i);
                tamanhoR++;
                if(tmax<tamanhoR){
                    tmax=tamanhoR;
                    imax=count;
                }
                count++;
            }
            tamanhoR=0;
            if(n==1) break;
            for (int j = 1; i*j < tamanho; j++){
                ePrimo[j*i]=false;
            }
            
        }
    }
    
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    long long int q; cin >> q;
    while (q--){
        long long int n; cin >> n;
        achaPrimos(n);
        int tamanho=divisores.size();
        if(tamanho==0){
            tamanho++;
            divisores.push_back(n);
        }
        if(tamanho>1 && tmax>1){
            printf("imax=%d tmax=%d\n",imax,tmax);
            for (int i = imax-tmax+1; i <= imax; i++){
                int aux=divisores[i];
                printf("aux=%d\n",aux);
                divisores.erase(divisores.begin()+i);
                divisores.push_front(aux);
            }
        }
        for (int i = 0; i < tamanho-1; i++){
            if(divisores[i+1]%divisores[i]!=0){
                divisores[i]=divisores[i]*divisores[i+1];
                divisores.erase(divisores.begin()+i+1);
                tamanho--;
                divisores.resize(tamanho);
                i--;
            }
        }
        cout << tamanho << endl;
        for (int i = 0; i < tamanho; i++){
            cout << divisores[i] << " ";
        }
        cout << endl;
    }
    
}