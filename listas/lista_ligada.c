#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

Node* lista = NULL;

int main(void)
{   
    int i, v;
    for (i = 0; i < 4; i++)
    {
        scanf("%d", &v);
        insertAtEnd(&lista, v);
    }
    infoList(lista);
    return 0;
}