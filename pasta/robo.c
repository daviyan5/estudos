#include <stdio.h>
#include <string.h>

int main() {
    char p1[6],p2[6],p3[6],p4[6];
    int id;
    scanf("%d",&id);
    if(id==0 || id==3 || id==4 || id==7 || id==9 || id == 10) strcpy(p1,"rosa");
    else strcpy(p1,"verde");
    if(id==0 || id==1 || id==4 || id==5 || id==9 || id == 10) strcpy(p2,"rosa");
    else strcpy(p2,"verde");
    if(id==4 || id==5 || id==6 || id==7 || id==9 || id == 11) strcpy(p3,"rosa");
    else strcpy(p3,"verde");
    if(id==0 || id==1 || id==2 || id==3 || id==9 || id == 11) strcpy(p4,"rosa");
    else strcpy(p4,"verde");
    printf("%s %s %s %s",p1,p2,p3,p4);
}