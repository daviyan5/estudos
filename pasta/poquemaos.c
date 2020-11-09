#include <stdio.h>
int main()
{int doce,p1,p2,p3;
scanf("%d %d %d %d",&doce,&p1,&p2,&p3);
if (doce<p1 && doce<p2 && doce<p3) printf("0");
else if ((doce>=p1 || doce>=p2 || doce>=p3) && (doce<p3+p2 && doce<p3+p1 && doce<p2+p1) ) printf("1");
else if ((doce>=p3+p2 || doce>=p1+p2 || doce>=p3+p1) && (doce<p1+p2+p3) ) printf("2");
else if ((doce>=p1+p2+p3) ) printf("3");

return 0;
}