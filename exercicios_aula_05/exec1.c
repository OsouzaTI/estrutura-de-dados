#include <stdio.h>
#include <stdlib.h>

typedef struct VDynamic {
    int size;
    int tSize;
    int* mem;
} VDynamic;

void printVDynamic(VDynamic* vdynamic){
    for (int i = 0; i < vdynamic->size; i++)
        printf("%d\n", *(vdynamic->mem+i));
}

void armazenar(VDynamic* vdynamic, int numero){
    if(vdynamic->size <= 1)
        vdynamic->mem = (int*)malloc(sizeof(numero));
    else
        vdynamic->mem = (int*)realloc(vdynamic->mem, vdynamic->size * vdynamic->tSize);
    /* size - 1 por causa do indice */
    *(vdynamic->mem+(vdynamic->size-1)) = numero;
}

int main(void)
{
    VDynamic vetor = {0, sizeof(int), NULL};
    int entrada;
    while(scanf("%d", &entrada)){
        if(!entrada){
            printVDynamic(&vetor);
            break;
        } 
        vetor.size++;
        armazenar(&vetor, entrada);
    }
    free(vetor.mem);
    return 0;
}