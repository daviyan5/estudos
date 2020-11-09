#include <stdio.h>
#include <string.h>
int main (){
    char string[52],ori[25][2],inv[25][3];
    int a=0,b=0;
    fgets(string,52,stdin);
    for (int i = 0; i < strlen(string); i++){
        if(string[i]!=' '){
            ori[b][a]=string[i];
            a++;
        }
        else{
            if(a<2) ori[b][a]=' ';
            a=0;
            b++;
        }
    }
    for (int i = 0,c = b; i <= b; c--,i++){
        inv[c][0]=ori[i][0];
        printf("digit=%c\n",ori[i][0]);
        if(ori[i][1]=='2'){
            inv[c][1]=ori[i][1];
            printf("2=%c\n",inv[c][1]);

        }
        else if(ori[i][1]==' '){
            inv[c][1]=39;
            printf("asps=%c\n",inv[c][1]);
        }
        else{
            inv[c][1]=' ';
            printf("espac=%c\n",inv[c][1]);
        }
    }
    for (int i = 0; i <= b; i++){
        if(inv[i][1]!=' ') printf("%c%c ",inv[i][0],inv[i][1]);
        else printf("%c ",inv[i][0]);
        
    }
    

    
    return 0;
}

