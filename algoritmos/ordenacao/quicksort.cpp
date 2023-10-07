#include <iostream>
using namespace std;

typedef long long LL;
typedef long double LD;

int n;
int num = 1;
int vezes = 0;

int pivot(int *&v, int l, int r) {
    //return l+(rand()%(r-l));
    //return r-1;
    //return l;
    return (r + l) / 2;
}

int partition(int *&v, int l, int r) {
    cout << "Partição entre " << l << " e " << r << endl;
    int k = pivot(v, l, r);
    cout << "Pivo: " << k << endl;
    swap(v[k], v[l]);
    int i = l, j = r - 1;

    while (i <= j) {
        while (i < r && v[i] <= v[l])
            i++;
        while (v[j] > v[l])
            j--;

        if (i < j)
            swap(v[i], v[j]);
    }

    swap(v[j], v[l]);

    cout << "Iteração numero: " << num << endl;
    num++;

    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }

    cout << endl;

    if (vezes == 0) {
        cout <<  "Continua?" << endl;
        string s;
        cin >> s;
        if (s != "sim")
            exit(1);
        else {
            cout << "Quantas vezes?" << endl;
            cin >> vezes;
            if (vezes < 0) vezes = 0;
        }
    } else {
        vezes--;
    }

    return j;
}

void quicksort(int *&v, int l, int r) {
    if (r - l > 1) {
        int p = partition(v, l, r);
        cout << "Tamanho da partição left: " << (p - l) << endl;
        quicksort(v, l, p);
        cout << "Tamanho da partição right: " << (r - p - 1) << endl;
        quicksort(v, p + 1, r);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        vezes = 0;
        num = 1;
        cout << "Digite a quantidade de valores" << endl;
        cin >> n;
        int *v = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << "Vetor desordenado: " << endl;
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
        quicksort(v, 0, n);
        cout << "Vetor ordenado: " << endl;
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
