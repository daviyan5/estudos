// Implementação do algoritmo de busca em largura (BFS)

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n;                                                              // Número de vértices
    int m;                                                              // Número de arestas
    try{
        cin >> n;
        cin >> m;
    }
    catch(const exception &e){
        cout << "Erro: " << e.what() << endl;
        return 1;
    }
    
    vector<vector<int>> adj(n);                                         // Lista de adjacência
    for(int i = 0; i < m; i++){
        try{
            int u, v;                                                   // Aresta u -> v
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        catch(const exception &e){
            cerr << "Erro: " << e.what() << endl;
            return 1;
        }
    }

    bool visitado[n];                                                   // Vetor de visitados
    int level[n];                                                       // Vetor de níveis
    int num_in_level[n];                                                // Vetor de número de vértices em cada nível
    for(int i = 0; i < n; i++){                                         // Inicializa os vetores
        visitado[i] = false;                    
        level[i] = -1;      
        num_in_level[i] = 0;        
    }       

    queue<int> fila;                                                    // Fila de vértices
    fila.push(0);                                                       // Insere o primeiro vértice
    visitado[0] = true;                                                 // Marca o primeiro vértice como visitado
    level[0] = 0;                                                       // Marca o primeiro vértice como nível 0
    num_in_level[0] = 1;                                                // Marca o primeiro vértice como o único vértice da camada 0
    cout << "Level 0: ";
    try{
        while(!fila.empty()){                                           // Enquanto a fila não estiver vazia
            int u = fila.front();                                       // Pega o primeiro vértice da fila
            fila.pop();                                                 // Remove o primeiro vértice da fila
            num_in_level[level[u]]--;                                   // Decrementa o número de vértices da camada
            cout << u << " ";                                           // Imprime o vértice
            if(num_in_level[level[u]] == 0) {
                cout << endl << "Level " << level[u] + 1 << ": ";
            }
            for(int v : adj[u]){                                        // Percorre os vértices adjacentes
                if(!visitado[v]){                                       // Se o vértice não foi visitado
                    fila.push(v);                                       // Insere o vértice na fila
                    level[v] = level[u] + 1;                            // Marca o nível do vértice
                    num_in_level[level[v]]++;                           // Incrementa o número de vértices da camada
                    visitado[v] = true;                                 // Marca o vértice como visitado
                }
            }
        }
    }
    catch(const exception &e){
        cerr << "Erro: " << e.what() << endl;
        return 1;
    }
    cout << "Fim" << endl;                                      

}