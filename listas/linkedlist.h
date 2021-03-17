#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdio.h>
#include <stdlib.h>
#include "logs.h"

#define ISNULL(x) (!(x))

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

void memoryException(){
    logs(ERROR, "memory allocate error!");
}

int insertAtBegin(Node** n, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(ISNULL(newNode)){
        memoryException();
        return (0);
    }
    newNode->value = value;
    newNode->next = *n;
    *n = newNode;
    return (1);
}

int insertAtEnd(Node** n, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!ISNULL(newNode)){
        memoryException();
        return (0);
    }
    newNode->value = value;
    newNode->next = NULL;
    
    /* caso seja o primeiro elemento */
    if(ISNULL(*n)){
        *n = newNode;
        return (1);        
    } 
    
    Node* p; /* Node auxiliar do loop */    
    /* o loop abaixo quebra quando o ultimo
    Node for encontrado  */
    for(p = *n;p;p = p->next)
        if(ISNULL(p->next)) break;
    /* apontando o proximo Node da lista para
    o newNode */
    p->next = newNode;
    
    return (1);
}

int infoList(Node* n){
    logs(WARNING, "teste de warning");
    if(!n){
        logs(ERROR, "node null pointer!");
        return (0);
    }
    Node* aux = n;
    while(aux != NULL){
        INFO;
        printf("value list: %d\n", aux->value);
        aux = aux->next;
    }
    return (1);
}



#endif



