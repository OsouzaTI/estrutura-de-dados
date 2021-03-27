#include <stdio.h>
#include <stdlib.h>

#define DUP_LINKED_LIST
#include "../libs/lists.h"

int main(void)
{
    dList* lista;
    dCreateList(&lista);
    printf("\nLista gerada\n");
    dInsertAtBegin(lista, 10);
    dInsertAtBegin(lista, 20);
    dInsertAtBegin(lista, 30);
    dInsertAtBegin(lista, 40);
    dInsertAtBegin(lista, 50);
    dInsertAtBegin(lista, 60);
    dPrintList(lista);
    printf("\nNova lista gerada\n");
    dRemoveValue(lista, 40);
    dPrintList(lista);
    return 0;
}