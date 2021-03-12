#include <iostream>
using namespace std;
//#define endl '\n'
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;
int n;
int pivot(int *&v,int l,int r){
    return l+(rand()%(r-l));
}
int partition(int *&v,int l,int r){
    cout << "Partição entre " << l << " e " << r << endl;
    int k = pivot(v,l,r);
    cout << "Pivo: " << k << endl;
    swap(v[k],v[l]);
    int i=l,j=r-1;
    while(i<=j){
        while(i<r and v[i]<=v[l]) i++;
        while(v[j]>v[l]) j--;
        if(i<j) swap(v[i],v[j]);
    }
    swap(v[j],v[l]);
    cout << "return Part: " << j << endl;
    return j;
}
void quicksort(int *&v,int l,int r){
    if(r-l>1){
        int p = partition(v,l,r);
        quicksort(v,l,p);
        quicksort(v,p+1,r);
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
        quicksort(v,0,n);
        cout << "Vetor ordenado: " << endl;
        forc(i,n){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}