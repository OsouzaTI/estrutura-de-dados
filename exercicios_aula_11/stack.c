#include "stack.h"

Stack* createStack(){
    Stack* p = (Stack*)malloc(sizeof(Stack));
    p->dim = 2;
    p->vet = (float*)malloc(p->dim*sizeof(float));
    p->n = 0;
    return p;
}

void stackPush(Stack* p, float v){    
    if(p->n == p->dim){
        p->dim *= 2;
        p->vet  = (float*)realloc(p->vet, p->dim*sizeof(float));
    }   
    printf("valor %.3f inserido na Stack na posicao %d\n", v, p->n); 
    p->vet[p->n++] = v;
}

float stackPop(Stack* p){
    float v = p->vet[--p->n];
    printf("valor %.3f removido da Stack\n", v);
    return v;
}

int stackEmpty(Stack* p){
    return (p->n == 0);
}

void stackFree(Stack* p){
    free(p->vet);
    free(p);
}

void stackInfo(Stack* p){
    int i;
    for(i = 0; i < p->n; i++){
        printf("Stack[%d] -> %.3f\n", i, p->vet[i]);
    }
}