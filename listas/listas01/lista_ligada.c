#include <stdio.h>
#include <stdlib.h>

#define LINKED_LIST
#include "../libs/lists.h"


int main(void)
{   
    sList* lista = NULL;
    sCreateList(&lista);
    scInsertAtBegin(lista, 9);
    scInsertAtBegin(lista, 10);
    scInsertAtBegin(lista, 12);
    scInsertAtBegin(lista, 13);
    scInfoList(lista);
    return 0;
}