#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;
typedef long double LD;
vector<LL> v;
LL n,k;
bool temSoma(LL x){ // Aqui se supõe que x é uma soma possivel pra o comprador
    LL kaux=0;
    for (int i=n-1;i>=1;i--) { // Aqui procuramos, pra todos os v[i], com v ordenado, se existe um numero == (x-v[i]) entre 0 e i
        kaux+=int(lower_bound(v.begin(),v.begin()+i,x-v[i])-v.begin()); // Ou seja, se existe um par distinto v[i],x-v[i] 
        if (kaux>=k) return true; // Se existir, significa que, para x-v[i], qualquer elemento entre 0 e i forma um par tal que a soma é menor que x, pois o vetor é ordenado
    } // Portanto, para cada i, contamos quantos elementos a são tais que a+v[i] <= x (ou seja, contamos os pares). se existirem mais pares que k, significa que independente da escolha dos adversarios nosso comprador sempre terá opção com a quantia x
    return false; // Se o numero de pares for menor que k, significa que os adversarios podem escolher pares de tal forma que apos a k-esima compra x não sera suficiente.

}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n >> k;
    v.resize(n);
    for(LL i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    LL l=-1;
    LL r=v[n-2]+v[n-1];
    while(l<=r){ //iteramos entre todas as somas possiveis e procuramos a menor soma tal que temSoma é satisfeito
        LL m = (l+r)/2;
        if(temSoma(m)){
            r=m-1;
        }
        else l=m+1;
    }
    cout << r << endl;
    return 0;
}