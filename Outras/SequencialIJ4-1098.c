#include <stdio.h>

int main(void)
{
    int c = 0, aux;
    float a[3]={1, 2, 3};
    //float c, d;
    for (float i = .0f; i < 2.2f; i+=.2f)
    {
        aux = (int)((i - (int)i)*10);        
        for (int j = 0; j < 3; j++){
            if(aux == 0){                
                printf("I=%.0f J=%.0f\n", i, a[j]+i);
            } else {                
                printf("I=%.1f J=%.1f\n", i, a[j]+i);
            } 
        }            
    }
    
    
    return 0;
}