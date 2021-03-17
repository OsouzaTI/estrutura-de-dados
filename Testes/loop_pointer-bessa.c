#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int main() {

    int i = -1;
    int *p = (int*)malloc(MAX * sizeof(int)); 
    *p = 10; // primeiro elemento igual a 10
    while(p[++i]){ 
        printf("Endereco: %p Guarda: %d\n", (p + i), *(p + i));
    }    

    return 0;
}