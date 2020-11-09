#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
int main(){   
    int h1,m1,h2,m2,h3,m3;
    cout << "Horas da primeira: "<< endl; cin >> h1;
    cout << "Minutos da primeira: " << endl; cin >> m1;
    cout << "Horas da segunda: "<< endl; cin >> h2;
    cout << "Minutos da segunda: " << endl; cin >> m2;
    cout << "Horas da terceira: "<< endl; cin >> h3;
    cout << "Minutos da terceira: " << endl; cin >> m3;
    if (h1>12) printf ("Primeira errada\n");
    else printf ("Primeira certa\n");
    if (h2>=24 || h2<0 || h2*60+m2!=h1*60+m1+192 ) printf("Segunda errada\n");
    else printf("Segunda certa\n");
    if (h3>=24 || h3<0 || h3*60+m3!=(h2*60)+m2-60) printf("Terceira errada\n");
    else printf("Terceira certa\n");
    if (h1>12 || h2>=24 || h2<0 || h2*60+m2!=h1*60+m1+192 || h3>=24 || h3<0 || h3*60+m3!=(h2*60)+m2-60) printf("falha");
    else printf("sucesso");
    return 0;
}