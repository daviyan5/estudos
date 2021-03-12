#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int alice(priority_queue<int>& arr,int& somaP, int& somaI){
    priority_queue<int> aux;
    int ans=0; bool sair=false;
    while(!arr.empty() and !sair){
        if(arr.top()%2==0){
            ans=arr.top();
            arr.pop();
            sair=true;
            somaP-=ans;
        }
        else if(somaI-arr.top()<=somaP){
            ans=arr.top();
            arr.pop();
            sair=true;
            somaI-=ans;
        }
        else{
            int a=arr.top();
            arr.pop();
            aux.push(a);
        }
    }
    if(arr.empty() and !sair) aux.pop();
    while(!aux.empty()){
        int a=aux.top();
        arr.push(a);
        aux.pop();
    }
     return ans%2==0?ans:0;
}
int bob(priority_queue<int>& arr,int& somaP, int& somaI){
    priority_queue<int> aux;
    int ans=0; bool sair=false;
    while(!arr.empty() and !sair){
        if(arr.top()%2==1){
            ans=arr.top();
            arr.pop();
            sair=true;
            somaI-=ans;
        }
        else if(somaP-arr.top()<=somaI){
            ans=arr.top();
            arr.pop();
            sair=true;
            somaP-=ans;
        }
        else{
            int a=arr.top();
            arr.pop();
            aux.push(a);
        }
    }
    if(arr.empty() and !sair) aux.pop();
    while(!aux.empty()){
        int a=aux.top();
        arr.push(a);
        aux.pop();
    }
    return ans%2==1?ans:0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int somaP=0;
        int somaI=0;
        priority_queue<int> arr;
        for(int i=0;i<n;i++){
            int a; cin >> a;
            arr.push(a);
            if(a%2==0) somaP+=a;
            else somaI+=a;
        }
        bool vez=true;
        int pAlice=0, pBob=0;
        while(!arr.empty()){
            if(vez) pAlice+=alice(arr,somaP,somaI);
            else pBob+=bob(arr,somaP,somaI);
            vez=!vez;
            printf("pBob=%d pAlice=%d somaP=%d somaI=%d\n",pBob,pAlice,somaP,somaI);
        }
        if(pAlice>pBob) cout << "Alice" << endl;
        else if(pBob>pAlice) cout << "Bob" << endl;
        else cout << "Tie" << endl;
    }
}