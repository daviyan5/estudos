#include <stdio.h>


int main(){
    float n1,n2,n3,n4,ne;
    
    scanf("%f %f %f %f",&n1,&n2,&n3,&n4);
    
    float media=(n1*2+n2*3+n3*4+n4*1)/10;
    
    printf("Media: %.1\n",media-0.05);
    
    if(media<5){
        printf("Aluno reprovado.\n");
    }
    else if(media<7){
        printf("Aluno em exame.\n");
        
        scanf("%f",&ne);
        
        printf("Nota do exame: %.1f\n",ne);
        
        media=(media+ne)/2;
        
        if(media>=5) printf("Aluno aprovado.\n");
        else printf("Aluno reprovado.\n");
        
        printf("Media final: %.1f\n",media);
    }
    else printf("Aluno aprovado\n.");
        
}