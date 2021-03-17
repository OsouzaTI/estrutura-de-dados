#include <stdio.h>
#include <stdlib.h>

#define MAX_N 5
int main(){
    
    int *numeros, i = 0;
    numeros = (int*)malloc(MAX_N * sizeof(int));
    
    while(*(numeros + i++)){
        printf("N: %d\n", *numeros);
    }
    

    return 0;
}