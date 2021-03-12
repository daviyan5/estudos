#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp(a, b) make_pair(a, b)
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long ll;
typedef pair<int,int> ii;
typedef long double LD;

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    int k=1;
    ofstream arq, arq2;
    arq.open("out3.in");
    arq2.open("outDebug.in");
    while(t--){
        int n, q;
        cin >> n >> q;
        ll min_ = 1e18, max_ = -1e18;
        
        bool aNegativo = false, bNegativo = false;
        vector<int> a(n), b(n);
        forc(i, n) {
            cin >> a[i];
            if(a[i] < 0) aNegativo = true;
        }
        forc(i, n) {
            cin >> b[i];
            if(b[i] < 0) bNegativo = true;
        }

        ll aux = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> qpa = {a.begin(),a.begin()+q}; 
        vector<int> qpb = {b.begin(),b.begin()+q};
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        vector<int> qua = {a.begin(),a.begin()+q};
        vector<int> qub = {b.begin(),b.begin()+q};

        //maximo max(soma qua*qub, soma qpa*qpb)
        priority_queue<int> pq;
        aux = 0;  // 
        forc(i, q){
            pq.push(qua[i]*qub[i]);
            //aux += qua[i]*qub[i];
        }
        //max_ = max(max_, aux);

        //aux = 0;
        forc(i, q){
            pq.push(qpa[i]*qpb[i]);
            //aux += qpa[i]*qpb[i];
        }
        forc(i, q){
            aux += pq.top();
            pq.pop();
        }
        max_ = max(max_, aux);

        //minimo se todos positivos qpa Iqpb
        //       se tivermos negativos
        //          1. qpa * 

        aux = 0;    
        if(!aNegativo && !bNegativo){           //nenhum dos dois tem negativo
            sort(qpb.rbegin(), qpb.rend());
            forc(i, q){
                aux += qpa[i]*qpb[i];
            }
            min_ = min(min_, aux);
        }
        else if(aNegativo && !bNegativo){       //so a tem negativo
            forc(i, q){
                aux += qpa[i]*qub[i];
            }
            min_ = min(min_, aux);
        }
        else if(!aNegativo && bNegativo){       //so b tem negativo
            forc(i, q){
                aux += qua[i]*qpb[i];
            }
            min_ = min(min_, aux);
        }   
        else{                                   //os dois tem negativo
            priority_queue<int, vector<int>, greater<int> > pq;
            aux = 0;  // 
            forc(i, q){
                pq.push(qua[i]*qpb[i]);
                //aux += qua[i]*qub[i];
            }
            //max_ = max(max_, aux);

            //aux = 0;
            forc(i, q){
                pq.push(qpa[i]*qub[i]);
                //aux += qpa[i]*qpb[i];
            }
            forc(i, q){
                aux += pq.top();
                pq.pop();
            }
            min_ = min(min_, aux);
        }

        arq << "Case #" << k << ": " << min_ << ' ' << max_ << endl;
        k++;
    }
    return 0;
}

/*
1
6 2 
4 2 5 5 5 5 
3 2 5 2 5 5


5
45 2
50 88 20 35 12 96 2 99 38 36 44 57 64 92 40 2 51 41 41 7 65 42 35 59 84 75 64 45 66 64 74 88 25 16 86 32 42 29 30 26 75 3 51 70 22
67 26 89 70 63 88 67 96 69 77 85 12 65 93 56 74 28 12 97 23 33 23 95 43 92 47 80 42 84 92 29 16 93 95 39 70 33 79 31 63 13 1 58 97 49
42 2
56 59 80 92 83 13 82 42 70 98 53 91 38 23 80 39 77 22 2 8 73 87 53 65 51 100 78 83 36 59 99 93 56 28 32 77 7 17 48 79 91 56
32 88 2 10 16 55 92 61 56 43 7 72 14 27 68 11 87 73 64 58 68 35 78 68 61 68 44 61 7 24 24 59 11 27 84 54 90 1 100 10 75 41
37 2
17 40 20 49 69 96 6 39 14 32 67 42 88 75 42 72 69 72 71 93 26 57 57 5 57 40 63 96 6 27 87 7 35 36 81 97 15
78 47 65 99 65 73 6 52 3 81 23 2 85 5 53 7 52 47 93 75 29 91 100 31 84 6 74 43 65 64 32 50 15 59 87 61 50
47 2
79 93 44 33 31 43 99 88 85 71 46 76 9 43 89 41 57 5 55 45 13 49 68 60 60 86 55 91 11 17 68 36 68 9 92 75 35 37 31 57 41 25 68 75 21 25 94
23 60 43 64 50 22 58 78 4 89 30 16 11 58 38 20 42 30 100 76 95 52 78 41 37 50 35 36 55 34 27 76 24 55 72 78 83 52 88 51 14 51 98 24 92 71 84
45 2
90 7 45 51 38 57 30 6 68 13 84 1 71 28 12 75 88 83 42 22 26 78 88 88 20 6 32 29 42 87 45 41 29 25 47 89 51 82 36 46 79 50 64 56 67
14 3 19 61 12 93 82 88 4 80 61 37 41 30 87 43 24 43 77 54 38 31 37 52 18 55 59 39 25 34 27 46 17 51 60 84 33 54 51 5 98 95 49 71 46


1 2 3 5 7 8 8
2 4 5 6 7 8 9
p/ q =3;

1 2 3
2 4 5

1 2 3
5 4 2

Case #1: -5022 1558

1
9 4
-3 -2 -1 0 1 2 3 4 5
-18 1 2 3 4 5 6 7 8

-90 -24 -14-6

*/