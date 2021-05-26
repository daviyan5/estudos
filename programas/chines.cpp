    #include <stdio.h>  
    #include <string.h>  
    #include <math.h>  
    #include <bits/stdc++.h>
    using namespace std;
    int a[100010];  
    int main(){  
        int i,j,n,m,s,t,k;  
        int pos,sum,mx;  
        while(true){
            scanf("%d %d",&n,&m);  
            for(i=0;i<=n-1;i++){  
                scanf("%d",&a[i]);  
            }  
            mx=0; k=0;  
            for(i=0,pos=-1,sum=0;i<=n-1;i++){  
                if(i!=0){  
                    sum-=a[i-1];  
                }  
                k=0;  
                if(pos+1<i){  
                    pos=i-1;  
                    sum=0;  
                }  
                for(j=pos+1;j<=n-1;j++){  
                    if(sum+a[j]<=m){  
                        k=1;  
                        sum+=a[j];  
                        pos=j;  
                    }
                    else break;    
                }  
                if((j-i)>mx) mx=j-i;
                if(n-i-1<=mx) break; 
                cout << sum << " " << mx << " " << i << " " << pos << endl;
            }  
            printf("%d\n",mx);
            break;
        }  
        return 0;  
    }  