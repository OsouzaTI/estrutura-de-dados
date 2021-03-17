#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int* data = NULL, size = 0, n;    
    while(1){
        /* recebe um numero 'n' */
        scanf("%d", &n);
        /* caso 'n' for igual a 0 */
        if(!n){
            if(!size)break;/* caso primeiro elemento seja 0 */
            /* printa todos os elementos */
            for(int i = 0; i < size; i++)printf("%d\n", *(data+i));
            break;
        }
        /*
            caso 'size' seja igual a 0
            sera alocado um espaco inicial
            de memoria
        */
        if(!size) data = (int*)malloc(++size*sizeof(int));
        /*
            caso data ja exista entao sera realocada para a 
            entrada de mais um elemento
         */
        else data = (int*)realloc(data, ++size*sizeof(int));
        /* atribui o elemento (n) */
        *(data+(size-1)) = n;
    }
    /* limpa memoria alocada dinamicamente */
    free(data);
    return 0;
}