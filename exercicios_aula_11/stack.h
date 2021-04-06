#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int n;
    int dim;
    float* vet;
} Stack;

Stack*  createStack();
void    stackPush(Stack* p, float v);
float   stackPop(Stack* p);
int     stackEmpty();
void    stackFree();
void    stackInfo(Stack* p);

#endif