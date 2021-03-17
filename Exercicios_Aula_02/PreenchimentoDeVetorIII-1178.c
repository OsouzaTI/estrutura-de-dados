#include <stdio.h>
#include <stdlib.h>
#define MAX 99

int main(){
    /* alocacao dinamica com MAX elementos */
    double* N = (double*)calloc(MAX, sizeof(double));
    double T, aux;
    scanf("%lf", &T);
    aux = T;
    for (int i = 0; i <= MAX; i++)
    {    
        *(N+i) = aux;
        aux /= 2;
        printf("N[%d] = %.4f\n", i, *(N+i));
    }
    return 0;
}