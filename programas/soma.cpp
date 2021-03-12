#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b;
    cin >> a >> b;
    if(a==0 || b==0){
        cout << "0" << endl;
    }
    else{
        if(b>a) swap(b,a);
        int dum=0;
        if(b<0 && a<0){
            b=abs(b); a=abs(a);
            while(b--){
                dum+=a;
            }
        }
        else if(b<0){
            while(b++){
                dum-=a;
            }
        }
        else{
            while(b--){
                dum+=a;
            }
        }
        cout << dum << endl;
    }
    return 0;
}

