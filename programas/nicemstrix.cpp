#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int m,n;
        cin >> n >> m;
        vector<vector<int>> mat;
        mat.resize(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                long long int a; cin >> a;
                mat[i].push_back(a);
            }
        }
        long long int ans=0;
        for(int i=0;i<n/2;i++){
            for(int j=0;j<m/2;j++){
                int dif1,dif2,dif3,dif4;
                // v1 -x- v2 -y- v3 -z- v4
                //minima distancia = minimo entre 3x+2y+z, x+2y+z e x+2y+3z
                vector<int> aux={mat[i][j],mat[n-i-1][j],mat[i][m-j-1],mat[n-i-1][m-j-1]};
                sort(aux.begin(),aux.end());
                long long int x= aux[1]-aux[0];
                long long int y= aux[2]-aux[1];
                long long int z= aux[3]-aux[2];
                /*dif1=abs(mat[i][j]-mat[n-i-1][j])+abs(mat[i][j]-mat[i][m-j-1])+abs(mat[i][j]-mat[n-i-1][m-j-1]);
                dif2=abs(mat[i][j]-mat[n-i-1][j])+abs(mat[n-i-1][j]-mat[i][m-j-1])+abs(mat[n-i-1][j]-mat[n-i-1][m-j-1]);
                dif3=abs(mat[i][m-j-1]-mat[n-i-1][j])+abs(mat[i][j]-mat[i][m-j-1])+abs(mat[i][m-j-1]-mat[n-i-1][m-j-1]);
                dif4=abs(mat[n-i-1][m-j-1]-mat[n-i-1][j])+abs(mat[n-i-1][m-j-1]-mat[i][m-j-1])+abs(mat[i][j]-mat[n-i-1][m-j-1]);*/
                long long int ex1=3LL*x+2LL*y+z;
                long long int ex2=x+2LL*y+z;
                long long int ex3=x+2LL*y+3LL*z;
                ans+=min(ex1,min(ex2,ex3));
            }
        }
        if(n%2==1){
            int p1=m-1,p2=0;
            while(p1>p2){
                ans+= abs(mat[n/2][p1]-mat[n/2][p2]);
                p1--; p2++;
            }
        }
         if(m%2==1){
            int p1=n-1,p2=0;
            while(p1>p2){
                ans+= abs(mat[p1][m/2]-mat[p2][m/2]);
                p1--; p2++;
            }
        }
        cout << ans << endl;

    }
}