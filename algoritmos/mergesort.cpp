#include <iostream>
using namespace std;
//#define endl '\n'
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;
int n;

void merge(int *&v,int l,int r){
    cout << "Entrou merge de " << l << " ate " << r << endl;
    int aux[n];
    int m=(l+r)/2;
    int i=l,j=m;
    for(int k=l;k<r;k++){
        if(j==r){
            cout << "Entrou 1 i: " << i << " v[i] " << v[i] << endl;
            aux[k]=v[i];
            i++;
        }
        else if(i==m){
            cout << "Entrou 2 j: " << j << " v[j] " << v[j] << endl;
            aux[k]=v[j];
            j++;
        }
        else if(v[i]<=v[j]){
            cout << "Entrou 3 i: " << i << " v[i] " << v[i] << endl;
            aux[k]=v[i];
            i++;
        }
        else{
            cout << "Entrou 4 j: " << j << " v[j] " << v[j] << endl;
            aux[k]=v[j];
            j++;
        }
    }
    for(int k=l;k<r;k++){
        v[k]=aux[k];
        cout << aux[k] << " ";
    }
    cout<< endl;
}
void msort(int *&v,int l,int r){
    if(r-l>=2){
        int m=(l+r)/2;
        msort(v,l,m);
        msort(v,m,r);
        merge(v,l,r);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cout << "Digite a quantidade de valores" << endl;
        cin >> n;
        int *v=(int*)malloc(n*sizeof(int));
        forc(i,n){
            cin >> v[i];
        }
        cout << "Vetor desordenado: " << endl;
        forc(i,n){
            cout << v[i] << " ";
        }
        cout << endl;
        msort(v,0,n);
        cout << "Vetor ordenado: " << endl;
        forc(i,n){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}