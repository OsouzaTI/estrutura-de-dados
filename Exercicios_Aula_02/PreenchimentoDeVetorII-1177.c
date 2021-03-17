#include <stdio.h>
#include <stdlib.h>
#define MAX 999

int main(){
    int T, aux = 0;
    /*
        Alocando array inteiro de MAX elementos no heap
        e zerando (calloc)
    */
    int* N = (int*)calloc(MAX, sizeof(int));
    /*
        limite max da repeticao
        ex: entrada -> 3
            resultado: 0, 1, 2
    */
    scanf("%d", &T); 
    for (int i = 0; i <= MAX; i++)
    {    
        /*
            iterando de 0 a MAX repetindo valores de 0 a T - 1
            e salvando no vetor na posicao i
        */
        *(N+i) = aux++;
        if(aux > T - 1) aux = 0;
        printf("N[%d] = %d\n", i, *(N+i));
    }
    return 0;
}