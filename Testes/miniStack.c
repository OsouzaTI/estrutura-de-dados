#include <stdio.h>
#include <stdlib.h>

enum STACK_TYPE {
    INT = 0,
    FLOAT
} typedef STACK_TYPE;

struct STACK {
    void* mem;
    int size;
    int type;
    int typeSize;
    void* top;    
} typedef STACK;

void pop(STACK* p){
    if(p->size < 0) return;
    printf("Valor %d removido da pilha!\n", *((int*)p->mem+(p->size-1)));
    p->mem = realloc(p->mem, (p->size-1)*p->typeSize);
    p->size--;
}

void push(STACK* p, void* value){
    p->size++;
    if(p->size == 0){ /* caso -1, foi para 0 ( primeira inicializacao ) */
        p->mem = malloc(p->typeSize);
        p->size++;
    }else{
        // aumenta em um a capacidade
        p->mem = realloc(p->mem, (p->size+1) * p->typeSize); 
    }
    
    switch (p->type)
    {
        case INT:{
            p->top = ((int*)p->mem+(p->size-1));
            *((int*)p->mem+(p->size-1)) = *((int*)value);
            break;    
        } 
        case FLOAT:{
            p->top = ((float*)p->mem+(p->size-1));
            *((float*)p->mem+(p->size-1)) = *((float*)value);
            break;    
        } 
        default: printf("Tipo de pilha nao reconhecido!\n"); break;
    }
}

void printSTACK(STACK* p){
    for (int i = 0; i < p->size; i++)
        printf("[%d] -> %d\n", i, *((int*)p->mem + i));
}

int isEmpty(STACK* p){
    p->size > 0 ? 0 : 1;
}

void destroy(STACK* p){
    free(p->mem);
}

int main(void)
{
    STACK *p = (STACK*)malloc(sizeof(STACK));
    p->size = -1;
    p->type = INT;
    p->typeSize = sizeof(int);
    /* Teste EMPILHAMENTO */
    int numero = 1;

    while (numero < 100)
    {
        push(p, &numero);
        numero++;
    }    
    
    printSTACK(p);

    while(isEmpty(p)){
        pop(p);
    }

    destroy(p);

    return 0;
}