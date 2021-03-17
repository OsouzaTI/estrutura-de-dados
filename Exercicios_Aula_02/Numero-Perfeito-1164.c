#include <stdio.h>
int main(){

    int X, D;
    int* N; // ¯\_(ツ)_/¯

    scanf("%d", N); // N entradas
    while(N > 0){
        D = 0; /* Somador dos divisores de X */
        scanf("%d", &X); // entrada
        /* 
            loop de 1 ate metade inteira de X, pois
            numeros a partir de X/2(e menor que X) 
            para i resultarao em uma divisao que não
            tem resto 0
        */
        for (int i = 1; i <= X/2; i++)        
            if(X%i == 0)D+=i;

        if(X==D) printf("%d eh perfeito\n", X);
        else printf("%d nao eh perfeito\n", X);

        N--; /* controlador do loop (N vezes) */
    }

    return 0;
}