#include <iostream>
using namespace std;

int main(){
    int n,m,zeros=0,zeros2=0;
    cin >> n;
    int vetor[n+2];
    vetor[0]=-1;
    vetor[n+1]=-1;
    for (int i=1;i<=n;i++){
        cin >> m;
        vetor[i]=m;
    }
    for(int i=1;i<=n;i++){
        if (vetor[i]==-1){
            vetor[i]=vetor[i-1]+1;
            if(vetor[i-1]==-1) vetor[i]++;
        }
        else zeros++;
    }
    for(int i=1;i<=n;i++){
        if (vetor[n]==0 or vetor[n+2-i]!=-1){
            if(vetor[n+1-i]>vetor[n+2-i]+1 or zeros2==zeros){
                vetor[n+1-i]=vetor[n+2-i]+1;
            }
            if (vetor[n+1-i]==0) zeros2++;
        }
        if (vetor[n+1-i]>9) vetor[n+1-i]=9;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << vetor[i]<< " ";
    }
    return 0;
}