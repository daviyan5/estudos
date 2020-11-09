#include <stdio.h>
#include <math.h>
#include <string.h>

struct re{
    double x1,y1,x2,y2;
};
struct ci{
    double x1,y1,r;
};

int main()
{
    double xp,yp;
    struct ci circu;
    struct re reta;
    long int i,n,r=0,c=0;
    char p[10],circ[]="circulo",ret[]="retangulo";
    scanf("%lf %lf %ld",&xp,&yp,&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",&p);
        if(strcmp(p,circ)==0)
        {
           scanf("%lf %lf %lf",&circu.x1,&circu.y1,&circu.r);
           if ((circu.x1-xp)*(circu.x1-xp)+(circu.y1-yp)*(circu.y1-yp)<=circu.r*circu.r) c++;
        }
        else if (strcmp(p,ret)==0)
        {
           scanf("%lf %lf %lf %lf",&reta.x1,&reta.y1,&reta.x2,&reta.y2);
           if(reta.x1<=xp && reta.y1<=yp && reta.x2>=xp && reta.y2>=yp) r++;
        }
    }
    printf("Retangulos: %ld\nCirculos: %ld\n",r,c);
    



    return 0;
}