#include <stdio.h>
#include <stdlib.h>

#define LINKED_LIST
#include "../libs/lists.h"

sNode* lista = NULL;

int main(void)
{   
    int i, v;
    // for (i = 0; i < 3; i++)
    // {
    //     scanf("%d", &v);
    //     sInsertAtEnd(&lista, v);
    // }
    sInsertAtEnd(&lista, 9);
    sInsertAtEnd(&lista, 10);
    sInsertAtEnd(&lista, 4);
    sInsertAtEnd(&lista, 3);
    sInsertAtEnd(&lista, 5);
    sInsertAtEnd(&lista, 7);
    sSwapKeys(&lista, 9, 4);

    infoList(lista);
    /* troca os valores entre dois nodos */
    swapValue(atPosition(lista, 0),atPosition(lista, 1));
    infoList(lista);
    /* troca dois nodos entre si (pela chave) */
    swapKeys(&lista, 4,5);
    bubbleSort(lista, getSize(lista)-1, CRESCENT);
    infoList(lista);
    return 0;
}