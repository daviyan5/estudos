    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
     
     
    int main(){
        ios::sync_with_stdio(0); cin.tie(nullptr);
        int t; cin >> t;
        while(t--){
            int n; cin >> n;
            map<int,int> conj;
            for(int i=1;i<=2*n;i++) conj[i]=0;
            for (int i = 0; i < n; i++){
                int a;
                cin >> a;
                conj[a]++;
            }
            for (int i = 1; i <= 2*n; i++){
                if(conj[i]>1){   
                    conj[i+1]++;
                    conj[i]--;
                }
            }
            int total=0;
            for(int i=1;i<=2*n+1;i++){
                if(conj[i]>0) total++;
                printf("conj[%d]=%d\n",i,conj[i]);
            }
            cout << total << endl;
            
        }
    }