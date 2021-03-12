#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> s1,s2;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        s1.push_back(a);
    }
    for(int i=0;i<n;i++){
        int a; cin >> a;
        s2.push_back(a);
    }
    bool g1=true,g2=true;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    int c1=0,c2=0,j=0,k=0;
	for(int i=0;i<n;i++){
		while(j<n){
            if(s1[j]>s2[i]){
                c1++;
                j++;
                break;
            }
            j++;
        }
        while(k<n){
            if(s2[k]>s1[i]){
                c2++;
                k++;
                break;
            }
            k++;
        }
	}
	if(c1>n-c1 and c2>n-c2) cout<<"Both" << endl;
	else if(c1>n-c1) cout<<"First" << endl;
	else if(c2>n-c2) cout<<"Second" << endl;
	else cout<<"None" << endl;
}