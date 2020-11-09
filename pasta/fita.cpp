#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int zer[n],um[n],m;
    unsigned int dist=n+1;
    for (int i=1; i<=n; i++){
        cin >> m;
        if (m==-1) {
            um[i]=i;
            zer[i]=0;
        }
        else if(m==0){
            zer[i]=i;
            um[i]=0;
        }
    }
    for(int i=1; i<=n; i++){
        if(zer[i]==i){
            dist=0;
        }
        else{
            for(int j=1;j<=n;j++){
                if (zer[j]!=0){
                    if ((unsigned)um[i]-zer[j]<dist){
                        dist=um[i]-zer[j];
                    }
                }
            }

        }
        cout << dist;
        return 0;

    }
}