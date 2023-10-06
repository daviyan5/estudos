/*answer: 
For every additional 5 meters, a 5 meter car can be placed at this position,
Or put a 10 meter car in this position and the previous position
dp[i]=K*dp[i-1]+L*dp[i-2]
Code:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e6;
ll n,K,L;
struct node
{
    ll t[2][2];
}a,b;
node pp(node x,node y)
{
    node r;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            r.t[i][j]=0;
            for(int k=0;k<2;k++)
            {
                r.t[i][j]=(r.t[i][j]+x.t[i][k]*y.t[k][j])%mod;
            }
        }
    }
    return r;
}
void printa(node a){
    cout << endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout << a.t[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void quickpow(ll m)
{
    while(m)
    {
        if(m&1)a=pp(a,b);
        b=pp(b,b);
        m=m>>1;
        printa(a);
        printa(b);
    }
}
int main()
{
    scanf("%lld%lld%lld",&n,&K,&L);
    K=K%mod;L=L%mod;
    b.t[0][0]=K;b.t[0][1]=1;
    b.t[1][0]=L;b.t[1][1]=0;
    n=n/5;
    if(n==1)printf("%06lld\n",K);
    else if(n==2)printf("%06lld\n",(K*K+L)%mod);
    else
    {
        a.t[0][0]=(K*K+L)%mod;
        a.t[0][1]=K;
        printa(a); printa(b);
        quickpow(n-2);
        printf("%06lld\n",a.t[0][0]%mod);
    }
    return 0;
}