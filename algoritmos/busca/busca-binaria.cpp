// Busca, em um vetor ordenado, pelo menor e maior indíce cujo valor é igual a um valor dado.

#include <iostream>
#include <vector>

using namespace std;

pair<int,int> busca_binaria(int val, vector<int> &v){
    int l = 0, h = v.size() - 1;                                            // Inicializa os limites da busca
    int m;
    while(l < h){
        m = (l + h) / 2;
        if(v[m] < val) l = m + 1;                                           // Se o valor do meio for menor que o valor buscado, atualiza o limite inferior
        else h = m;                                                         // Se o valor do meio for maior que o valor buscado, atualiza o limite superior
    }
    if(v[l] != val) return {-1, -1};                                        // Se o valor não foi encontrado, retorna {-1, -1}
    int menor = l;                                                          // Salva o menor índice  
    h = v.size() - 1;                                                       // Atualiza o limite superior
    while(l < h){
        m = (l + h + 1) / 2;                                                
        if(v[m] > val) h = m - 1;                                           // Se o valor do meio for maior que o valor buscado, atualiza o limite superior
        else l = m;
    }
    return {menor, h};
}

int main(){
    int n;
    try{
        cin >> n;
    }
    catch(const exception &e){
        std::cerr << e.what() << '\n';
    }

    vector<int> v(n);
    try{
        for(int i = 0; i < n; i++) cin >> v[i];
    }
    catch(const exception &e){
        std::cerr << e.what() << '\n';
    }

    int val;
    try{
        cin >> val;
    }
    catch(const exception &e){
        std::cerr << e.what() << '\n';
    }

    pair<int,int> p = busca_binaria(val, v);
    cout << "Menor e maior índice = " << val << " : " << p.first << " " << p.second << endl;
    if(p.first == -1 or p.second == -1) cout << "Valor não encontrado" << endl;
    else if (!(v[p.first] == val  and 
               v[p.second] == val and 
               (p.first == 0 or v[p.first - 1] != val) and 
               (p.second == n - 1 or v[p.second + 1] != val))) cout << "Busca incorreta..." << endl; 
    else cout << "Busca correta!" << endl;
    
}