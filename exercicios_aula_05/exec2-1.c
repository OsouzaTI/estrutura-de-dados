#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE_STRING 100

struct Node
{
    char* value;
} typedef Node;


struct LinkedList
{
    Node* child;
    int size;
} typedef LinkedList;

void insert(LinkedList* ptrLinkedList, char* string){
    char** aux = NULL;
    if(ptrLinkedList->size <= 0){
        ptrLinkedList->child = (Node*)malloc(sizeof(Node*));
    }else{
        ptrLinkedList->child = (Node*)realloc(ptrLinkedList->child, (ptrLinkedList->size+1) * sizeof(Node*));
    }
    aux = &(ptrLinkedList->child+ptrLinkedList->size)->value;
    int len = strlen(string);
    *aux = (char*)malloc(len*sizeof(string[0]));
    strcpy(*aux, string);
    printf("[%p] -> %s\n", *aux, *aux);
    ptrLinkedList->size++;
}

void imprimeLista(LinkedList* ptrLinkedList){
    for (int i = 0; i < ptrLinkedList->size; i++){
        char** aux = &(ptrLinkedList->child+i)->value;
        printf("[%p] -> %s\n", ptrLinkedList->child+i, *aux);
    }
}

void destroy(LinkedList* ptrLinkedList){
    free(ptrLinkedList->child);
    free(ptrLinkedList);
}

LinkedList* inicialization(){
    LinkedList* ptrLinkedList = (LinkedList*)malloc(sizeof(LinkedList));
    ptrLinkedList->size = 0;
}

int main(void)
{
    char entrada[MAX_BUFFER_SIZE_STRING];
    LinkedList* lista = inicialization(lista);
    while(1){
        gets(entrada);
        if(*entrada == '\0'){
            imprimeLista(lista);
            break;
        }
        insert(lista, entrada);
    }
    destroy(lista);
    return 0;
}