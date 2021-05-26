#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
pair<int,char> sol;

//Movemos a peça pra alguma casa possivel, e marcamos todas as casas atacadas pelas 3 peças
//Checamos se o rei inimigo pode se mover para alguma casa nao atacada

//Passo 1 : Achar as casas possiveis e fazer um movimento
// Criterios : Uma peça não pode se mover pra fora do iro
//             Uma peça não pode se mover para uma casa já ocupada
//             No caso do Rei e Bispo, a peça nao pode se mover para uma casa que outra peça estiver no caminho
//             O rei não pode se mover para uma casa atacada pelo rei negro

//Passo 2 : Marcar as casas atacadas pelas 3 peças
// Criterios : Uma casa é atacada se uma peça pode se mover até ela
//             Não é necessario marcar as casas atacadas pelo rei das pretas, visto o proximo passo


//Passo 3 : Checar se o rei negro pode ir a alguma casa não atacada
// Criterios : Casas com peças não estão atacadas simplesmente por ter uma peça lá.

vector<vector<int>> atacados(map<int,pair<int,int>> mapa){
    /*vector<vector<char>> aux(8);
    for(int i=0;i<8;i++){
        aux[i].resize(8);
        fill(aux[i].begin(),aux[i].end(),'0');
    }
    aux[mapa[1].first][mapa[1].second]='K';
    aux[mapa[2].first][mapa[2].second]='B';
    aux[mapa[3].first][mapa[3].second]='N';
    aux[mapa[4].first][mapa[4].second]='P';
    printf("Posição de ataque\n");
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout << aux[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/
    vector<vector<int>> ataq(8);
    for(int i=0;i<8;i++){
        ataq[i].resize(8);
        fill(ataq[i].begin(),ataq[i].end(),0);
    }
    for(int i=mapa[1].first-1;i<=mapa[1].first+1;i++){ 
            if(i<0) continue; if(i>7) continue;
            for(int j=mapa[1].second-1;j<=mapa[1].second+1;j++){
                if(j<0) continue; if(j>7) continue;
                ataq[i][j]=1;
            }
    }
    for (int i = mapa[2].first-1,j=mapa[2].second-1; i>=0 && j>=0; i--,j--){
        if(i==mapa[1].first && j==mapa[1].second){
            ataq[i][j]=2;
            break;
        }
        if(i==mapa[3].first && j==mapa[3].second){
            ataq[i][j]=2;
            break;
        }
        ataq[i][j]=2;
    }
    for (int i = mapa[2].first-1,j=mapa[2].second+1; i>=0 && j<8; i--,j++){
        if(i==mapa[1].first && j==mapa[1].second){
            ataq[i][j]=2;
            break;
        }
        if(i==mapa[3].first && j==mapa[3].second){
            ataq[i][j]=2;
            break;
        }
        ataq[i][j]=2;
    }
    for (int i = mapa[2].first+1,j=mapa[2].second-1; i<8 && j>=0; i++,j--){
        if(i==mapa[1].first && j==mapa[1].second){
            ataq[i][j]=2;
            break;
        }
        if(i==mapa[3].first && j==mapa[3].second){
            ataq[i][j]=2;
            break;
        }
        ataq[i][j]=2;
    }
    for (int i = mapa[2].first+1,j=mapa[2].second+1; i<8 && j<8; i++,j++){
        if(i==mapa[1].first && j==mapa[1].second){
            ataq[i][j]=2;
            break;
        }
        if(i==mapa[3].first && j==mapa[3].second){
            ataq[i][j]=2;
            break;
        }
        ataq[i][j]=2;
    }
    for(int i=mapa[3].first-2;i<=mapa[3].first+2;i++){
        if(i<0 || i>7 || i==mapa[3].first) continue;
        if(i==mapa[3].first-2 || i==mapa[3].first+2){
            for(int j=mapa[3].second-1;j<=mapa[3].second+1;j++){
                if(j<0 || j>7 || j==mapa[3].second) continue;
                ataq[i][j]=3;
            }
        }
        else{
            for(int j=mapa[3].second-2;j<=mapa[3].second+2;j+=2){
                if(j<0 || j>7 || j==mapa[3].second) continue;
                ataq[i][j]=3;
            }
        }
    }
    return ataq;
}

bool mate(vector<vector<int>> ataq,int x,int y){ //Se a casa que o rei está e todas as que ele pode ir estão atacadas, retorne true
    /*printf("Entrou mate\n");
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout << ataq[i][j] << " ";
        }
        cout << endl;
    }*/
    for(int i=x-1;i<=x+1;i++){ 
            if(i<0) continue; if(i>7) continue;
            for(int j=y-1;j<=y+1;j++){
                if(j<0) continue; if(j>7) continue;
                if(ataq[i][j]==0) return false;
            }
    }
    return true;
}
bool move(vector<vector<int>> mat,map<int,pair<int,int>> mapa,int num){
    if(num==1){ // Rei
        for(int i=mapa[1].first-1;i<=mapa[1].first+1;i++){ 
            if(i<0) continue; if(i>7) continue;
            for(int j=mapa[1].second-1;j<=mapa[1].second+1;j++){
                if(j<0) continue; if(j>7) continue;
                if(mat[i][j]==0){ //Casa que o rei pode ir
                    int x=mapa[1].first, y=mapa[1].second; //salvo a posição que ele tava
                    mapa[1].first=i; mapa[1].second=j;
                    vector<vector<int>> ataq = atacados(mapa); // crio uma matriz dos ataques
                    if(mate(ataq,mapa[4].first,mapa[4].second)){ //pergunto se essa matriz de ataq implica num mate
                        sol.first=i+1; sol.second=j+'a'; //se sim crio a solução e retorno verdadeiro
                        return true;
                    }
                    else{
                        mapa[1].first=x; mapa[1].second=y;
                    }

                }
            }
        }
        return false;
    }
    else if(num==2){ //Bispo
        for (int i = mapa[2].first-1,j=mapa[2].second-1; i>=0 && j>=0; i--,j--){
            if(i==mapa[1].first && j==mapa[1].second){
                break;
            }
            if(i==mapa[3].first && j==mapa[3].second){
                break;
            }
            int x=mapa[2].first,y=mapa[2].second;
            mapa[2].first=i; mapa[2].second=j;
            vector<vector<int>> ataq = atacados(mapa);
            if(mate(ataq,mapa[4].first,mapa[4].second)){ //pergunto se essa matriz de ataq implica num mate
                sol.first=i+1; sol.second=j+'a'; //se sim crio a solução e retorno verdadeiro
                return true;
            }
            else{
                mapa[2].first=x; mapa[2].second=y;
            }
        }
        for (int i = mapa[2].first-1,j=mapa[2].second+1; i>=0 && j<8; i--,j++){
            if(i==mapa[1].first && j==mapa[1].second){
                break;
            }
            if(i==mapa[3].first && j==mapa[3].second){
                break;
            }
            int x=mapa[2].first,y=mapa[2].second;
            mapa[2].first=i; mapa[2].second=j;
            vector<vector<int>> ataq = atacados(mapa);
            if(mate(ataq,mapa[4].first,mapa[4].second)){ //pergunto se essa matriz de ataq implica num mate
                sol.first=i+1; sol.second=j+'a'; //se sim crio a solução e retorno verdadeiro
                return true;
            }
            else{
                mapa[2].first=x; mapa[2].second=y;
            }
        }
        for (int i = mapa[2].first+1,j=mapa[2].second-1; i<8 && j>=0; i++,j--){
            if(i==mapa[1].first && j==mapa[1].second){
                break;
            }
            if(i==mapa[3].first && j==mapa[3].second){
                break;
            }
            int x=mapa[2].first,y=mapa[2].second;
            mapa[2].first=i; mapa[2].second=j;
            vector<vector<int>> ataq = atacados(mapa);
            if(mate(ataq,mapa[4].first,mapa[4].second)){ //pergunto se essa matriz de ataq implica num mate
                sol.first=i+1; sol.second=j+'a'; //se sim crio a solução e retorno verdadeiro
                return true;
            }
            else{
                mapa[2].first=x; mapa[2].second=y;
            }
        }
        for (int i = mapa[2].first+1,j=mapa[2].second+1; i<8 && j<8; i++,j++){
            if(i==mapa[1].first && j==mapa[1].second){
                break;
            }
            if(i==mapa[3].first && j==mapa[3].second){
                break;
            }
            int x=mapa[2].first,y=mapa[2].second;
            mapa[2].first=i; mapa[2].second=j;
            vector<vector<int>> ataq = atacados(mapa);
            if(mate(ataq,mapa[4].first,mapa[4].second)){ //pergunto se essa matriz de ataq implica num mate
                sol.first=i+1; sol.second=j+'a'; //se sim crio a solução e retorno verdadeiro
                return true;
            }
            else{
                mapa[2].first=x; mapa[2].second=y;
            }
        }
        return false;
    }
    else{ // Cavalo
        for(int i=mapa[3].first-2;i<=mapa[3].first+2;i++){
            if(i<0 || i>7 || i==mapa[3].first) continue;
            if(i==mapa[3].first-2 || i==mapa[3].first+2){

                for(int j=mapa[3].second-1;j<=mapa[3].second+1;j++){
                    if(j<0 || j>7 || j==mapa[3].second) continue;
                    if(mat[i][j]==0){
                        int x=mapa[3].first, y=mapa[3].second; //salvo a posição que ele tava
                        mapa[3].first=i; mapa[3].second=j;
                        vector<vector<int>> ataq = atacados(mapa); // crio uma matriz dos ataques
                        if(mate(ataq,mapa[4].first,mapa[4].second)){ //pergunto se essa matriz de ataq implica num mate
                            sol.first=i+1; sol.second=j+'a'; //se sim crio a solução e retorno verdadeiro
                            return true;
                        }
                        else{
                            mapa[3].first=x; mapa[3].second=y;
                        }
                    }

                }
            }
            else{
                for(int j=mapa[3].second-2;j<=mapa[3].second+2;j+=2){
                    if(j<0 || j>7 || j==mapa[3].second) continue;
                    if(mat[i][j]==0){
                        int x=mapa[3].first, y=mapa[3].second; //salvo a posição que ele tava
                        mapa[3].first=i; mapa[3].second=j;
                        vector<vector<int>> ataq = atacados(mapa); // crio uma matriz dos ataques
                        if(mate(ataq,mapa[4].first,mapa[4].second)){ //pergunto se essa matriz de ataq implica num mate
                            sol.first=i+1; sol.second=j+'a'; //se sim crio a solução e retorno verdadeiro
                            return true;
                        }
                        else{
                            mapa[3].first=x; mapa[3].second=y;
                        }
                    }
                }
            }
        }
        return false;
    }
}




int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    string rB,bB,cB,rN;
    vector<vector<int>> mat(8);
    map<int,pair<int,int>> mapa;
    for (int i = 0; i < 8; i++){
        mat[i].resize(8);
        fill(mat[i].begin(),mat[i].end(),0);
    }
    getline(cin,rB);
    mat[rB[1]-'1'][rB[0]-'a']=1;
    mapa[1]=make_pair(rB[1]-'1',rB[0]-'a');

    getline(cin,bB);
    mat[bB[1]-'1'][bB[0]-'a']=2;
    mapa[2]=make_pair(bB[1]-'1',bB[0]-'a');

    getline(cin,cB);
    mat[cB[1]-'1'][cB[0]-'a']=3;
    mapa[3]=make_pair(cB[1]-'1',cB[0]-'a');

    getline(cin,rN);
    mat[rN[1]-'1'][rN[0]-'a']=4;
    mapa[4]=make_pair(rN[1]-'1',rN[0]-'a');
    
    for(int i=mapa[4].first-1;i<=mapa[4].first+1;i++){ //marcando as atacadas pelo rei negro
        if(i<0) continue; 
        if(i>7) continue;
        for(int j=mapa[4].second-1;j<=mapa[4].second+1;j++){
           if(j<0) continue; 
           if(j>7) continue;
           if(mat[i][j]==0) mat[i][j]=5;
        }
    }
    bool mateRei = move(mat,mapa,1);
    bool mateBispo = move(mat,mapa,2);
    bool mateCavalo = move(mat,mapa,3);
    
    if(mateCavalo){
        cout << 'N' << sol.second << sol.first << endl;
    }
    else if(mateBispo){
        cout << 'B' << sol.second << sol.first << endl;
    }
    else if(mateRei){
        cout << 'K' << sol.second << sol.first << endl;
    }
    else cout << "impossible" << endl;
}