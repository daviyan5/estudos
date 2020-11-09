#include <stdio.h>
#include <math.h>
#define PI 3.14159265359

int main()
{
    float x1,y1,x2,y2,x3,y3,d1,d2,d3,rad;
    scanf("%f %f %f %f %f %f",&x1,&y1,&x2,&y2,&x3,&y3);
    d1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    d2=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
    d3=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    rad=acos(((d1*d1)+(d2*d2)-(d3*d3))/(d1*d2*2));
    printf("%.2f",rad*180/PI);
    return 0;
}