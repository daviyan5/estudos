#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'

int main(){
    //ios::sync_with_stdio(0); cin.tie(nullptr);
    string linha;
    double velocidade=0;
    int tempot=0;
    double dist=0;
    int dias=0;
    while(getline(cin,linha)){
        if(linha=="acaba") break;
        int h,m,s;
        string ho; ho+=linha[0];ho+=linha[1]; h=stoi(ho); 
        string mi; mi+=linha[3];mi+=linha[4]; m=stoi(mi);
        string se; se+=linha[6];se+=linha[7]; s=stoi(se);
        double d=0;
        if(h*3600+m*60+s - tempot + dias*24*3600 < 0) dias++;
        int dif=h*3600+m*60+s - tempot + dias*24*3600;
        d=velocidade*dif;
        dist+=d;
        if(linha.size()>9){ //mudança de velocidade
            string ve;
            for(int i=9;i<linha.size();i++) ve+=linha[i];
            velocidade=stoi(ve);
            velocidade/=3.6;
        }
        else{ //fila
            printf("%02d:%02d:%02d %.2lf km\n",h,m,s,dist/1000);
        }
        tempot+=dif;
    }
}