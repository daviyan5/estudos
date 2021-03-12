#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    char frase[10000];
    scanf("%[^\n]s",frase);
    int freq[256];
    for (int i = 0; i < 256; i++){
        freq[i]=0;
    }
    for (int i = 0; i < strlen(frase); i++){
        freq[(int)frase[i]]++;
    }
    for (int i = 255; i >=0 ; i--){
        char a=i;
        if(freq[i]>0) printf("%c %d\n",a,freq[i]);
    }
    return 0;
    
    

}