#include <stdio.h>
#include <stdlib.h>
#include "../libs/arraylist.h"

Arraylist* listaA;
Arraylist* listaB;

int main(void)
{
    createList(&listaA);
    createList(&listaB);

    insert(listaA, 1);
    insert(listaA, 2);
    insert(listaA, 3);
    insert(listaA, 4);

    insert(listaB, 5);
    insert(listaB, 6);
    insert(listaB, 7);
    insert(listaB, 8);

    Arraylist* listaC = arrayConcat(listaA, listaB);
    infoArray(listaC);

    Arraylist* novoA;
    Arraylist* novoB;
    divideArray(listaC, &novoA, &novoB);
    printf("novoA:\n");
    infoArray(listaA);
    printf("novoB:\n");
    infoArray(listaB);

    Arraylist* d = copyArray(novoA);
    printf("D:\n");
    infoArray(d);

    int k = searchKey(d, 1231);
    printf("chave em %d\n", k);

    removeAtPosition(d, 5);
    printf("D:\n");
    infoArray(d);

    return 0;
}