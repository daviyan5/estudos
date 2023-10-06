#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n,q; cin >> n >> q;
    map<int,pair<int,int>> mapa;
    deque<int> d;
    int maior=INT_MIN;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        d.push_front(a);
        maior=max(a,maior);
    }
    vector<int> aux;
    //map<int,pair<int,int>> mapaux;
    int cont=0;
    while(true){
        int A=d.back();
        d.pop_back();
        int B=d.back();
        d.pop_back();
        if(A==maior){
            d.push_back(B);
            d.push_back(A);
            while(!d.empty()){
                aux.push_back(d.back());
                d.pop_back();
            }
            break;
        }
        if(B>A){
            d.push_front(A);
            d.push_back(B);
        }
        else{
            d.push_front(B);
            d.push_back(A);
        }
        cont++;
        mapa[cont]=make_pair(A,B);
        //printf("cont = %d A = %d B = %d\n",cont-1,A,B);
    }
    for(int i=0;i<q;i++){
        long long int a; cin >> a;
        if(a<=cont) cout << mapa[a].first << " " << mapa[a].second << endl;
        else cout << maior << " " << aux[(a-(cont+1))%(n-1)+1] << endl;
    }
}