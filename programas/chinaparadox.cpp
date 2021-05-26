    #include <cstdio>
    typedef long long ll;
    ll n,k;
    const ll mod=1000003;
    ll pow(ll a,ll b,ll p){ll t=1;for(a%=p;b;b>>=1LL,a=a*a%p)if(b&1LL)t=t*a%p;return t;}
    int main(){
        scanf("%lld %lld",&n,&k);
        if(n<=62&&k>1ll<<n){puts("1 1");return 0;}
        ll num=0; for(ll i=k-1;i;i>>=1)num+=i/2;
        ll b=1,a=pow(2,n,mod);
        for(ll i=1;i<=k-1;i++){
            ll tmp=(a-i+mod)%mod;
            b=b*tmp%mod;
            if(!tmp)break;
        }ll inv=pow(pow(2,num,mod),mod-2,mod);
        a=pow(a,k-1,mod);
        a=a*inv%mod; b=b*inv%mod;
        b=(a-b+mod)%mod;
        printf("%I64d %I64d\n",b,a);
        return 0;
    }