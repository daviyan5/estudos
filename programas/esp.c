#include <stdio.h>
#include <string.h>
int main (){
    char s[610],of[610];
    int a=0;
    fgets(s,610,stdin);
    for (int i = 0; i < strlen(s); i++){
        if(s[i]!=' ' || (s[i]==' ' && s[i+1]!= ' ')){
            of[a]=s[i];
            a++;
        }
    }
    printf("%s\n",of);
    
    return 0;
}

