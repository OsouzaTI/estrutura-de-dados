#ifndef LIST_DUP
#define LIST_DUP

#include <stdio.h>
#include <stdlib.h>

#define ISNULL(x)  (x == NULL)
#define ISEQUAL(x, y) (x == y)

/* inicio e fim da lista */
typedef struct dList dList;
/* nodos da lista */
typedef struct dNode dNode;

struct dList
{
    struct dNode *begin;
    struct dNode *end;
};

struct dNode
{
    int value;
    struct dNode *next;
    struct dNode *prev;
};

void memoryAlert(void* m){
    if(!m){
        printf("Erro ao criar dList!\n");
        exit(1);
    }
}

void dCreateList(dList** l){
    (*l) = (dList*)malloc(sizeof(dList));
    memoryAlert(*l);
    (*l)->begin = NULL;
    (*l)->end = NULL;
}

dNode* dCreateNode(){
    dNode* n = (dNode*)malloc(sizeof(dNode));
    return n;
}

void dInsertAtBegin(dList* l, int v){
    dNode* n = (dNode*)malloc(sizeof(dNode));
    n->value = v;
    n->next = l->begin;
    n->prev = NULL;
    if(!ISNULL(l->begin))
        (l->begin)->prev = n;
    else
        l->end = n;
    l->begin = n;
}

void dInsertAtEnd(dList* l, int v){
    dNode* n = dCreateNode();
    n->value = v;
    n->prev = l->end;
    n->next = NULL;
    if(!ISNULL(l->end)){
        l->end->next = n;
    }else{
        l->begin = n;
    }
    l->end = n;
}

dNode* dSearchNode(dList* l, int v){
    dNode* p;
    for(p = l->begin;p;p = p->next)
        if(ISEQUAL(p->value, v))return p;
    return NULL;
}

void dRemoveValue(dList* l, int v){
    dNode* p = dSearchNode(l, v);
    if(ISNULL(p)){
        printf("retornou nulo!\n");
        return;
    }
    if(p == l->begin)
        l->begin = p->next;
    else
        p->prev->next = p->next;

    if(p == l->end)
        l->end = p->prev;
    else
        p->next->prev = p->prev;

    free(p);
}

void dPrintList(dList* l){
    dNode* p;
    printf("Next: ");
    for(p = l->begin;p;p = p->next)
        printf("%d ->", p->value);
    printf("\nPrev: ");
    for(p = l->end;p;p = p->prev)
        printf("%d ->", p->value);
}   

#endif