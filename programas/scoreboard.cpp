#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp(a, b) make_pair(a, b)
#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> ii;

vector<LL> penalidade;

bool compare(const ii &a, const ii &b){
    if(a.first == b.first){
        if(penalidade[a.second] == penalidade[b.second]){
            return a.second < b.second;
        }
        return penalidade[a.second] < penalidade[b.second];
    }
    return a.first > b.first;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    int aux=1;
    ofstream arq;
    arq.open("out.in");
    while(t--){
        int n, q; //numero de times, numero de logs
        cin >> n >> q;
        vector<ii> pont(n);
        penalidade.resize(n+1, 0);
        vector<vector<vector<bool>>> passou(n); //passou[time][quest][input]
        
        forc(i, n){
            passou[i].resize(6);
            forc(j, 6) passou[i][j].assign(6, false);
        }

        forc(i, n) pont[i] = mp(0, i+1);
        forc(i, q){
            int tempo, id, prob, ipt, sim;
            cin >> tempo >> id >> prob >> ipt >> sim;
            if(sim){
                if(!passou[id-1][prob][ipt]){
                    passou[id-1][prob][ipt]=true;
                    pont[id-1].first+= (ipt*100);
                    penalidade[id] += tempo;
                }
            }
        }

        sort(pont.begin(), pont.end(), compare);
        arq << "Case #" << aux << ": ";
        for(auto e: pont){
            arq << e.second << " ";
        }
        penalidade.clear();
        arq << endl;
        aux++;
    }
    return 0;
}

//timestamp=2 teamid=1 problemid=1 inputid=1 scored=1
//100, 200, 300, 400 and 500 

/*
1
5 5
1 1 1 1 0 
2 1 1 1 1 
2 4 1 2 1  
3 2 1 2 0 
4 2 1 1 1 
*/