#include <stdio.h>
#include <math.h>


int main() {
    long int t;
    scanf("%ld",&t);
    for(int i=0;i<t;i++){
        long long int a,b;
        long int m;
        scanf("%lld %lld %ld",&a,&b,&m);
        printf("%lld\n",(a*b)%m);
    }
	return 0;
}