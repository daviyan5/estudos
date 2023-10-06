#include <stdio.h>
#include <stdlib.h>

int main(){
   int d1,d2,m1,m2,a1,a2,saiu=1,bis1=0,bis2=0;
   int df,mf,af,h=0;
   scanf("%d/%d/%d",&d1,&m1,&a1);
   scanf("%d/%d/%d",&d2,&m2,&a2);
   for (int i=d1,j=d2; saiu>0 ; i++,j--){
        
        if(a1%4==0 != (a1%100==0 && a1%400!=0)) bis1=1;
        else bis1=0;
        if (i==31 && (m1==4 || m1==6 || m1==9 || m1==11)){
            i=1;
            m1++;
        }
        if(bis1 && m1==2 && i==30){
            i=1;
            m1++;
        }
        else if(m1==2 && i==29 && !bis1){
            i=1;
            m1++;
        }
        if(i==32){
            i=1;
            m1++;
        }
        if(m1==13 && i==1){
            m1=1;
            a1++;
        }
        
        if(a2%4==0 != (a2%100==0 && a2%400!=0)) bis2=1;
        else bis2=0;
        if (j==0 && (m2==5 || m2==7 || m2==10 || m2==12)){
            j=30;
            m2--;
        }
        else if(j==0 && m2==3){
            if(bis2) j=29;
            else j=28;
            m2--;
        }
        else if(j==0){
            j=31;
            m2--;

        }
        if(m2==0 && j==31){
            m2=12;
            a2--;
        }
        printf("data1 = d1=%02d m1=%02d a1=%02d data 2: d2=%02d m2=%02d a2=%02d\n",i,m1,a1,j,m2,a2);
        if(i==j && m1==m2 && a1==a2) {
            saiu=0;
            d2=i;
            break;
        }
        else if((m1==m2 && a1==a2 && i>j) || (m1>m2 && a1==a2) || a1>a2 ){
            saiu=0;
            d2=j;
            h=12;
            break;
        }
   }
   printf("%02d/%02d/%04d %02d:00\n",d2,m2,a2,h);

}