#include <stdio.h>
#include <math.h>

int main()
{
    int a,b,c,num=1;
    scanf("%d %d %d",&a,&b,&c);
    if ((a%2==0 && a!=2) || a==1) a=-1;
    if ((b%2==0 && b!=2) || b==1) b=-1;
    if ((c%2==0 && c!=2) || c==1) c=-1;
    while (num<a && a!=-1 && a!=2){
        if (a%num==0 && num!=1) a=-1;
        else num=num+2;
        }
    num==1;
   while (num<b && b!=-1 && b!=2){
        if (b%num==0 && num!=1) b=-1;
        else num=num+2;
        }
    num==1;
   while (num<c && c!=-1 && c!=2){
        if (c%num==0 && num!=1) c=-1;
        else num=num+2;
        }
    num==1;
    if (a==-1 && b==-1 & c==-1) printf("Seguro");
    else if ((a!=-1 && b==-1 && c==-1) || (b!=-1 && a==-1 && c==-1) || (c!=-1 && b==-1 && a==-1)) printf("Possível Risco");
    else printf("Perigo");
    
    
return 0;
}