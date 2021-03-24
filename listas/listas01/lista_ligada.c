#include <stdio.h>
#include <stdlib.h>

#define SUPPORTED_ANSI_COLORS
#include "linkedlist.h"

LinkedList* lista = NULL;

int main(void)
{   
    int i, v;
    // for (i = 0; i < 3; i++)
    // {
    //     scanf("%d", &v);
    //     insertAtEnd(&lista, v);
    // }
    insertAtEnd(&lista, 9);
    insertAtEnd(&lista, 10);
    insertAtEnd(&lista, 4);
    insertAtEnd(&lista, 3);
    insertAtEnd(&lista, 5);
    insertAtEnd(&lista, 7);
    swapKeys(&lista, 9, 4);
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