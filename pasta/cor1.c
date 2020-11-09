#include <stdio.h>

int main()
{
    float volt,litro,dist,consumo=(1/13);
    int i=1;
    scanf("%f %f %f",&volt,&litro,&dist);
    if (dist<0) printf("Vai pa onde, kinho?");
    else if (volt<75) printf("Zilboi trollou o kinho");
    else if (dist<=5) printf("Parabens, Kinho. Vc vai comer um morceguinho.");
    else 
    {
        volt=volt-10;
        dist=dist-5;
        if (((volt-50)/2)>=dist)
        {
            while(dist<2.5)
            {
                dist=dist-2.5;
                consumo=consumo+(1/(13-0.5*i));
                i++;
            }
            if (consumo*2.5 + dist*(1/(13-0.5*i))>litro) printf("Pobre Kinho. Vai ficar no meio do caminho.");
            else printf("Parabens, Kinho. Vc vai comer um morceguinho.");
        }
        else 
        {
            while (i<((volt-50)/5))
            {
                dist=dist-2.5;
                consumo=consumo+(1/(13-0.5*i));
                i++;
            }
            if (consumo*2.5+(dist-((volt-50)/2))/10>litro) printf("Pobre Kinho. Vai ficar no meio do caminho.");
            else printf("Parabens, Kinho. Vc vai comer um morceguinho.");
        }
    }
    return 0;
}
    