#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINKED_LIST
#include "../libs/lists.h"

int main(){

    sList* lista1 = NULL;
    sList* lista2 = NULL;

    sCreateList(&lista1);
    sCreateList(&lista2);

    clock_t t;
    int i;

    for(i = 0; i < 500; i++)
        sInsertAtBegin(lista1, rand()%100);
    for(i = 0; i < 500; i++)
        sInsertAtEnd(lista1, rand()%100);

    sInfoList(lista1);
    
    t = clock();   
    sBubbleSort(lista1, sGetSize(lista1), CRESCENT);
    t = clock() - t;
    printf(
        "the nodes has swapped in %lf\n",
        ((double)t)/(CLOCKS_PER_SEC/1000)
    );        
    sInfoList(lista1);
    destroyList(lista1);
    sInfoList(lista1);
    return 0;

}