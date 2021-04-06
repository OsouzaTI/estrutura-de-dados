#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int ini, fim;
    int qtde;
    int MAX_SIZE;
    int *array;
} Fila;

Fila* criaFila(int MAX_SIZE){

    Fila* Q = (Fila*)malloc(sizeof(Fila));
    Q->array = (int*)malloc(sizeof(int)* MAX_SIZE);
    Q->MAX_SIZE = MAX_SIZE;
    Q->qtde = 0;
    Q->ini = 0;
    Q->fim = 0;

    return Q;

}

void destroyQueue(Fila** Q){
    Fila* Qaux = *Q;
    free(Qaux->array);
    free(Qaux);
    *Q = NULL;
}

int emptyQueue(Fila* Q){
    return (Q->qtde == 0);
}

void insertQueue(Fila* Q, int elem){

    if(Q->qtde >= Q->MAX_SIZE){
        printf("Fila cheia\n");
        return;
    }

    Q->array[Q->fim] = elem;
    Q->fim++;
    Q->qtde++;

}

int removeQueue(Fila* Q){

    int elem = 0;
    if(emptyQueue(Q)){
        printf("fila vazia");
    }
    elem = Q->array[Q->ini];
    Q->ini++;
    Q->qtde--;

    return elem;    

}



void infoQueue(Fila* Q){
    if(emptyQueue(Q)){
        printf("Fila vazia\n");
        return;
    }
    int i;
    for(i = Q->ini; i < Q->fim; i++)
        printf("%d ", Q->array[i]);
    puts("\n");
}

int main(void)
{

    Fila* fila = criaFila(5);

    insertQueue(fila, 10);
    int a = removeQueue(fila);
    printf("removido %d\n", a);

    insertQueue(fila, 20);
    insertQueue(fila, 30);
    insertQueue(fila, 40);
    insertQueue(fila, 80);
    insertQueue(fila, 95);
    infoQueue(fila);

    return 0;
}