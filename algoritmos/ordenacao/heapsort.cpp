#include <bits/stdc++.h>
using namespace std;
class Heap{
public:
    Heap(int n){
        h.resize(n);
        heapsize = 0;
    }
    void extract(){
        int mn = INT_MIN;
        if(heapsize == 0) return;
        mn = h[0];
        h[0] = h[heapsize];
        heapsize--;
        bubble(0);
    }
    void bubble(int i){
        while(i > 0 && h[i] >= h[(i-1)/2]){
            int id1 = h[i];
            int id2 = h[(i-1)/2];
            swap(h[i],h[(i-1)/2]);
            i = (i-1)/2;
        }
    }
private:
    int heapsize;
    vector<int> h;

};
void heapsort(vector<int> &v){
    Heap pq(v.size());
    
}
void printa(vector<int> &v){
    for(auto &u:v){
        cout << u << " ";
    }
    cout << endl;
}
int main(){
    vector<int> v;
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        v.push_back(a);
    }
    printa(v);
    heapsort(v);
    printa(v);
}