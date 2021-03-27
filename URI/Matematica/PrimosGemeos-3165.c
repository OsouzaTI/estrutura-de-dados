#include <stdio.h>
#include <stdlib.h>

void primosGemeos(int N){
    /* espaco alocado para 4bytes */
    int *numerosPrimos = (int*)malloc(sizeof(int));
    int primosAteN = 0, aux = 0, k = N;
    while(1){
        if(k <= 0)break;        
        for (int i = 1; i <= k/2; i++)
            if(k%i == 0)aux++;
        if(aux == 1){
            *(numerosPrimos+(primosAteN++)) = k;
            int bytes = (primosAteN+1)*sizeof(int);
            realloc(numerosPrimos, bytes);
        }
        aux = 0;
        k--;
    }  

    int dif, *saida;
    saida = (int*)malloc(2*sizeof(int));
    for (int i = primosAteN-2; i >= 0; i--){
        dif = *(numerosPrimos+i) - *(numerosPrimos+i+1);
        if(dif == 2){
            *saida = *(numerosPrimos+i+1);
            *(saida+1) = *(numerosPrimos+i);
        }
    }
    printf("%d %d\n", *saida, *(saida+1));
    free(numerosPrimos);
    free(saida);
}

int main(void)
{
    int N;
    scanf("%d", &N);
    primosGemeos(N);
    return 0;
}