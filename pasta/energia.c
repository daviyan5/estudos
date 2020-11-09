#include <stdio.h>

int main(){
    float kw,p;
    scanf("%f",&kw);
    if(kw<(35/1.35)) kw=35/1.35;
    if(kw<100) p=1.35;
    else if(kw<300) p=1.55;
    else if(kw<575) p=1.75;
    else p=2.15;
    if(kw<=300) printf("%.2f\n%.2f",kw*p,p);
    else printf("%.2f\n%.2f",kw*p*1.1,p);
}