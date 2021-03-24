#ifndef LINKED_LIST
#define LINKED_LIST
/*=======================================================
    Name        : linkedlist.h                         
    Author      : Ozeias souza                         
    Data        : 18/03/2021                           
    Version     : 0.2-a                                
    Description : a standalone library for linked list 

    version 0.2-a
        + bubbleSort( the bubble sort use the function
        swapValues inside, then only the values are exchanged
        not the node)
        + getSize
        + atPosition
        + swapValues

    

=======================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ANSI_DEBUG
/* its a helper for debug using ANSI colors */
#ifdef ANSI_DEBUG
#include "logs.h"
#endif

#define ISNULL(x)       (x==NULL)
#define ISEQUAL(a, b)   (a == b)
#define MALLOC(a)   (a*)malloc(sizeof(a))

enum errorList {
    MEMORY,
    EMPTY
};

enum sortOrder {
    CRESCENT,
    DECRESCENT
};

typedef struct List
{
    int value;
    struct List* next;
} LinkedList;

void listException(int error){
    switch (error)
    {
        case MEMORY:
            logs(ERROR, "memory allocate error");
            break;
        case EMPTY:
            logs(ERROR, "empty list");
            break;
        default:
            logs(ERROR, "exception type undefined");            
            break;
    }
}

int insertAtBegin(LinkedList** n, int value){
    LinkedList* newLinkedList = MALLOC(LinkedList);
    if(ISNULL(newLinkedList)){
        listException(MEMORY);
        return (0);
    }
    newLinkedList->value = value;
    newLinkedList->next = *n;
    *n = newLinkedList;
    return (1);
}

int insertAtEnd(LinkedList** n, int value){
    if(ISNULL(*n))logs(WARNING, "primeiro elemento");
    LinkedList* newLinkedList = MALLOC(LinkedList);
    if(ISNULL(newLinkedList)){
        listException(MEMORY);
        return (0);
    }
    newLinkedList->value = value;
    newLinkedList->next = NULL;
    
    /* caso seja o primeiro elemento */
    if(ISNULL(*n)){
        *n = newLinkedList;
        return (1);        
    } 
    
    LinkedList* p; /* LinkedList auxiliar do loop */    
    /* o loop abaixo quebra quando o ultimo
    LinkedList for encontrado  */
    for(p = *n;p;p = p->next)
        if(ISNULL(p->next)) break;
    /* apontando o proximo LinkedList da lista para
    o newLinkedList */
    p->next = newLinkedList;    
    return (1);
}

LinkedList* insertAtEndV2(LinkedList* lista, int v){
    /* primeiro elemento */
    if(lista == NULL){
        printf("lista vazia\n");
        lista = (LinkedList*)malloc(sizeof(LinkedList));
        lista->value = v;
        lista->next = NULL;
        return lista;
    }else{
        LinkedList* newElement = (LinkedList*)malloc(sizeof(LinkedList));
        newElement->value = v;
        newElement->next = NULL;
        LinkedList* aux;
        for(aux = lista;aux;aux=aux->next)
            if(!aux->next)break;
        aux->next = newElement;
        return lista;
    }
}

int removeAtPosition(LinkedList* n, int key){
    unsigned char keyExists = 0;
    LinkedList *p, *q;
    char buffer[100];

    if(ISNULL(n)){
        listException(EMPTY);
        return (0);
    }

    for(p = n;p;p = p->next){
        if(ISEQUAL(p->value, key)){
            keyExists = 1;
            break;
        }
        q = p;
    }

    /* caso não encontre a chave de busca */
    if(!keyExists){
        sprintf(buffer, "key %d not found", key);
        logs(DEBUG, buffer);
        return (1);
    }
    /* O LinkedList anterior a 'p' aponta pro posterior a p
    logo, 'p' deixa de pertencer a conexao de nos */
    q->next = p->next;
    sprintf(buffer, "removed { key: %d,  value %d }", key, p->value);
    logs(INFO, buffer);
    free(p);

    return (1);

}

int removeEnd(LinkedList** n){
    
    if(ISNULL(*n)){
        listException(EMPTY);
        return (0);
    }

    /* a lista possui apenas um elemento */
    if(ISNULL((*n)->next)){
        logs(DEBUG, "list have one element");
        printf("item %d removed\n", (*n)->value);
        free(*n); /* limpa o LinkedList */
        *n = NULL;

        return (1);
    }

    LinkedList *p, *q;
    /* chegara no ultimo elemento que apontara
    para NULL encerrando loop antes da atrbuicao
    de 'q' */
    for(p = *n;p;p = p->next){
        if(ISNULL(p->next)) break;
        q = p;
    }
    printf("item %d removed\n", p->value);
    free(q->next); /* apaga o ultimo elmento */
    q->next = NULL;
    return (1);
}

LinkedList* listcpy(LinkedList* n){
    LinkedList *copy, *p;
    for(p = n;p;p = p->next){
        insertAtEnd(&copy, p->value);
    }
    return copy;
}

int isParent(LinkedList* n1, LinkedList* n2){
    if(ISNULL(n1)||ISNULL(n2)){
        listException(EMPTY);
        return (0);
    }

    if(ISEQUAL(n1->next, n2)) return (1);
    if(ISEQUAL(n2->next, n1)) return (1);

    return (0);
}

/* aloca memoria para um nodo novo */
LinkedList* alocateNode(){
    LinkedList* newNode = MALLOC(LinkedList);
    if(ISNULL(newNode)){
        listException(MEMORY);
        return NULL;
    }
    return newNode;
}

int swapKeys(LinkedList** n, int mKey, int nKey){

    if(ISEQUAL(mKey, nKey)){
        logs(WARNING, "mKey is equal to nKey");
        return (0);
    }
    /* m e n sao as chaves buscadas */
    unsigned char mExists = 0;
    unsigned char nExists = 0;
    LinkedList *p = NULL, // provavel mKey
         *q = NULL, // anterior mKey
         *r = NULL, // provavel nKey
         *s = NULL, // anterior nKey
         *aux = NULL; // auxiliar do swap
    
    if(ISNULL(*n)){
        listException(EMPTY);
        return (0);
    }

    if(ISNULL((*n)->next)){
        logs(ERROR, "list have just one element");
        return (0);
    }

    for (p = *n;p; p = p->next)
    {
        if(p->value == mKey){
            mExists = 1;
            break;
        }
        q = p;
    }

    /* caso nao encontre 'm' */
    if(!mExists){
        logs(ERROR, "key 'm' not exists");
        return (0);
    }

    for (r = *n;r; r = r->next)
    {
        if(r->value == nKey){
            nExists = 1;
            break;
        }
        s = r;
    }

    /* caso nao encontre 'n' */
    if(!nExists){
        logs(ERROR, "key 'n' not exists");
        return (0);
    }

    /* caso o 'm' seja o nodo
    anterior a 'n' */
    if(isParent(p, r)){
        logs(DEBUG, "swap entre nos consecutivos");

        /* caso 'p' seja o primeiro elemento da lista */
        if(ISNULL(q)){
            logs(DEBUG, "primeiro elemento em 'p'");
            *n = r;
            aux = r->next;
            r->next = p;
            p->next = aux;
            return (1);
        }

        /* caso 'n' seja o primeiro elemento da lista */
        if(ISNULL(s)){
            logs(DEBUG, "primeiro elemento em 'r'");            
            *n = p;
            r->next = p->next;
            p->next = r;
            return (1);
        }

        /* nodo anterior a 'm' aponta para onde 'n' apontava ' */
        q->next = p->next;
        /* 'm' aponta para onde o 'n' apontava */
        p->next = r->next;
        /* 'n' aponta para 'm' */
        r->next = p;

        return (1);

    }else{
        printf("nao sao parentes\n");
    }    

    /* casos onde 'm' e 'n' nao sao vizinhos porem 'm' e 
    o inicio da lista, fazendo com que 'q' seja NULL */
    if(ISNULL(q)){
        /* guarda o valor do proximo nodo a 'n' */
        aux = r->next;
        /* a cabeca da lista recebe 'n' */
        *n = r;
        /* 'n' aponta pra onde 'm' apontava */
        r->next = p->next;
        /* o nodo anterior a 'n' aponta para 'm' */
        s->next = p;
        /* o nodo 'm' aponta pra onde o 'n' apontava */
        p->next = aux;
        return (1);
    }

    /* casos onde 'm' e 'n' nao sao vizinhos e nem 'm' seja 
    o inicio da lista */  
    aux = r->next; /* guarda o valor do nodo apos 'n' */    
    /* o nodo anterior a 'm' aponta para 'n' */    
    q->next = r; 
    /* o nodo anterior a 'm' aponta para 'n' */
    s->next = p;
    /* o nodo 'n' aponta para o proximo nodo de 'm' */
    r->next = p->next;
    /* o nodo 'm' aponta para o proximo nodo de 'n' */
    p->next = aux;


    return (1);

}

int swapNodes(LinkedList** l, LinkedList* m, LinkedList* n){
    if(isListNull(m)||isListNull(n))return (0);

    LinkedList* antM = NULL; /* anterior a m */
    LinkedList* antN = NULL; /* anterior a n */
    LinkedList* aux, *p; /* auxiliar | iterador */
    int isParent = (m->next == n || n->next == m);
    int liM = 0, liN = 0;
    int _liM = 0, _liN = 0;
    for(p = *l;p;p = p->next){
        if(p->next == m){
            antM = p;
            _liM++;
        }
        if(p->next == n){
            antN = p;
            _liN++;
        }
        if(_liM == 0)liM++;
        if(_liN == 0)liN++;
    }

    if(!isParent){
        if(ISNULL(antM)){  
            printf("primeiro\n");
            (*l) = n; /* cabeca da lista */
            aux = n->next;
            n->next = m->next;
            antN->next = m;
            m->next = aux;
            return (1);
        }
        if(ISNULL(antN)){  
            printf("primeiro\n");
            (*l) = m; /* cabeca da lista */
            aux = m->next;
            m->next = n->next;
            antM->next = n;
            n->next = aux;
            return (1);
        }
        aux = n->next;
        antM->next = n;
        n->next = m->next;
        m->next = aux;
        antN->next = m;
        return (1);
    }else{
        if(liM < liN){
            m->next = n->next;
            n->next = m;
            if(!ISNULL(antM))
                antM->next = n;
            else (*l) = n;
            return (1);
        }
        aux = m->next;
        m->next = n;
        n->next = aux;
        if(!ISNULL(antN))
            antN->next = m;
        else (*l) = m;
        return (1);
    }   

}

/* recupera um nodo em uma posicao especifica */
LinkedList* atPosition(LinkedList* n,int i){
    LinkedList* p;
    int aux = 0;
    for (p = n;p;p = p->next){
        if(ISEQUAL(aux, i)){
            return p;
        }
        aux++;
    }
    logs(ERROR, "index not found");
    return NULL;    
}

/* recupera o tamanho de uma lista */
int getSize(LinkedList* n){
    
    int i = 0;
    LinkedList* p;
    
    if(ISNULL(n)){
        listException(EMPTY);
        return (0);
    }
    
    for (p = n;p;p = p->next)i++;
    return i;
}

int swapValue(LinkedList *a, LinkedList *b){

    int aux;

    if(ISNULL(a)||ISNULL(b)){
        listException(EMPTY);
        return (0);
    }

    aux = a->value;
    a->value = b->value;
    b->value = aux;

    return (1);

}

int bubbleSort(LinkedList* n, int k, int sortType){

    LinkedList *p, *q;
    int i;
    
    if(ISNULL(n)){
        listException(EMPTY);
        return (0);
    }

    if(k < 1) return (1);

    for(i = 0; i < k; i++){
        p = atPosition(n, i);
        q = atPosition(n, i+1);
        if(ISNULL(p)||ISNULL(q))break;
        
        switch (sortType)
        {
            case CRESCENT:{
                if(p->value > q->value)
                    swapValue(p, q);
            }break;
            case DECRESCENT:{
                if(p->value < q->value)
                    swapValue(p, q);
            }break;        
            default:{
                logs(ERROR, "order type not defined");
                return (0);
            }break;
        }
            
    }

    return bubbleSort(n, k-1, sortType);

}


int infoList(LinkedList* n){

    LinkedList* p;
    char buffer[100];
    char space[100] = "";
    int k = 0;

    if(ISNULL(n)){
        logs(ERROR, "LinkedList null pointer!");
        return (0);
    }

    for (p = n;p;p = p->next)
    {
        k++;
        for(int i = 0; i < k; i++)strcat(space, " ");
        sprintf(buffer, BLUE "Node[%d]:\n%svalue:" RED "%d\n%s" RESET, k, space, p->value, space);
        printf(buffer);
    }
    printf("\n");
    return (1);
}



#endif

