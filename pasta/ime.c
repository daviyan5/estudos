#include <stdio.h>

int main(){
    int count=4,total=0,full=0;
    int string[10];
    for (int i = 0; i < count; i++){
        string[0]=i;
        for (int j = 0; j < count; j++){
            string[1]=j;
            for (int k = 0; k < count; k++){
                string[2]=k;
                for (int l = 0; l < count; l++){
                    string[3]=l;
                    for (int m = 0; m < count; m++){
                        string[4]=m;
                        for (int n = 0; n < count; n++){
                            string[5]=n;
                            for (int o = 0; o < count; o++){
                                string[6]=o;
                                for (int p = 0; p < count; p++){
                                    string[7]=p;
                                    for (int q = 0; q < count; q++){
                                        string[8]=q;
                                        for (int r = 0; r < count; r++){
                                            full++;
                                            string[9]=r;
                                            int ach=0;
                                            for (int s = 0; s < count; s++){
                                                if(string[s]==ach){
                                                    ach++;
                                                }
                                                else continue;
                                            }
                                            if(ach==3) total++;
                                            
                                        }
                                        
                                    }
                                    
                                }
                                
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    printf("Total=%d full=%d\n",total,full);
    
    
}