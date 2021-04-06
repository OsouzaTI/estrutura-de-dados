#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{

    Stack* pilha = createStack();
    for(int i = 0; i < 10; i++)
        stackPush(pilha, rand()%100);

    stackInfo(pilha);
    stackPop(pilha);
    stackInfo(pilha);
    return 0;
    
}
