#ifndef LIST_SIM
#define LIST_SIM
/*=======================================================
    Name        : linkedlist.h                         
    Author      : Ozeias souza                         
    Data        : 18/03/2021                           
    Version     : 0.2-a                                
    Description : a standalone library for linked list 

    version 0.2-a
        + bubbleSort( the bubble sort use the function
        sSwapValues inside, then only the values are exchanged
        not the node)
        + getSize
        + sAtPosition
        + sSwapValues

    

=======================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ISNULL(x)       (x==NULL)
#define ISEQUAL(a, b)   (a == b)
#define MALLOC(a)       (a*)malloc(sizeof(a))

/* tipos de erros para listas simplesmentes encadeadas */
enum errorList {
    MEMORY,
    EMPTY
};

/* ordem a ser feita a ordenacao */
enum sortOrder {
    CRESCENT,
    DECRESCENT
};

/* definicao do tipo sList(Lista Simplesmente encadeada) */
typedef struct sList
{
    struct sNode* first;
} sList;

/* definicao do tipo sNode(nodos que compoem uma lista simplesmente encadeada) */
typedef struct sNode
{
    int value;
    struct sNode* next;
} sNode;

/* tratamento de erros em listas simplesmentes encadeadas */
void sListException(int error){
    switch (error)
    {
        case MEMORY:
            printf("memory allocate error\n");
            break;
        case EMPTY:
            printf("empty list\n");
            break;
        default:
            printf("exception type undefined\n");            
            break;
    }
}

/* aloca espaco pra uma sList */

int sCreateList(sList** l){
    (*l) = (sList*)malloc(sizeof(sList));
    (*l)->first = NULL;
}

/* insere no inicio da lista simplesmente encadeada */
int sInsertAtBegin(sList* n, int value){
    sNode* newsNode = MALLOC(sNode);
    if(ISNULL(newsNode)){
        sListException(MEMORY);
        return (0);
    }
    newsNode->value = value;
    newsNode->next = n->first;
    n->first = newsNode;
    return (1);
}

int sInsertAtPosition(sList* n, int v, int pos){
    if(ISNULL(n->first))return (0);

    sNode* newsNode = MALLOC(sNode);
    newsNode->value = v;
        
    int i = 0;
    sNode *p, *q;
    for(p = n->first;p;p = p->next){
        if(ISEQUAL(i, pos))break;
        i++;
        q = p;
    }

    q->next = newsNode;
    newsNode->next = p;

    return (1);
}

/* insere no fim da lista simplesmente encadeada */
int sInsertAtEnd(sList* n, int value){
    sNode* newsNode = MALLOC(sNode);
    if(ISNULL(newsNode)){
        sListException(MEMORY);
        return (0);
    }
    newsNode->value = value;
    newsNode->next = NULL;
    
    /* caso seja o primeiro elemento */
    if(ISNULL(n->first)){
        n->first = newsNode;
        return (1);        
    } 
    
    sNode* p; /* sNode auxiliar do loop */    
    /* o loop abaixo quebra quando o ultimo
    sNode for encontrado  */
    for(p = n->first;!ISNULL(p);p = p->next)
        if(ISNULL(p->next)) break;
    /* apontando o proximo sNode da lista para
    o newsNode */
    p->next = newsNode;    
    return (1);
}

/* remove um elemento especificado pela chave em uma lista simplesmente encadeada */
int sRemoveAtPosition(sNode* n, int key){
    unsigned char keyExists = 0;
    sNode *p, *q;

    if(ISNULL(n)){
        sListException(EMPTY);
        return (0);
    }

    for(p = n;!ISNULL(p);p = p->next){
        if(ISEQUAL(p->value, key)){
            keyExists = 1;
            break;
        }
        q = p;
    }

    /* caso não encontre a chave de busca */
    if(!keyExists){
        printf("key %d not found\n", key);
        return (1);
    }
    /* O sNode anterior a 'p' aponta pro posterior a p
    logo, 'p' deixa de pertencer a conexao de nos */
    q->next = p->next;
    printf("removed { key: %d,  value %d }\n", key, p->value);
    free(p);

    return (1);

}

/* remove o elemento final de uma lista simplesmente encadeada */
int sRemoveEnd(sList* n){
    
    if(ISNULL(n->first)){
        sListException(EMPTY);
        return (0);
    }

    sNode *p, *q;
    /* chegara no ultimo elemento que apontara
    para NULL encerrando loop antes da atrbuicao
    de 'q' */
    for(p = n->first;!ISNULL(p);p = p->next){
        if(ISNULL(p->next)) break;
        q = p;
    }
    printf("item %d removed\n", p->value);
    free(q->next); /* apaga o ultimo elmento */
    q->next = NULL;
    return (1);
}

/* retorna o inicio da copia de uma lista simplesmente encadeada */
sList* sListcpy(sNode* n){
    sList *copy;
    sNode *p;
    sCreateList(&copy);
    for(p = n;!ISNULL(p);p = p->next){
        sInsertAtEnd(copy, p->value);
    }
    return copy;
}

/* retorna (1) se os dois nodos passados sao parentes ou (0) caso nao */
int sIsParent(sNode* n1, sNode* n2){
    if(ISNULL(n1)||ISNULL(n2)){
        sListException(EMPTY);
        return (0);
    }

    if(ISEQUAL(n1->next, n2)) return (1);
    if(ISEQUAL(n2->next, n1)) return (1);

    return (0);
}

/* aloca memoria para um novo nodo do tipo "sNodo" */
sNode* sAlocateNode(){
    sNode* newNode = MALLOC(sNode);
    if(ISNULL(newNode)){
        sListException(MEMORY);
        return NULL;
    }
    return newNode;
}

/* faz a troca entre duas chaves passadas se estiverem na lista retornando (1) ou em caso de falha (0) */
int sSwapValue(sNode *a, sNode *b){

    int aux;

    if(ISNULL(a)||ISNULL(b)){
        sListException(EMPTY);
        return (0);
    }

    aux = a->value;
    a->value = b->value;
    b->value = aux;

    return (1);

}

/* faz a troca entre dois nodos passados se estiverem na lista retornando (1) ou em caso de falha (0) */
int sSwapNodes(sList* l, sNode* m, sNode* n){
    sNode* antM = NULL;
    sNode* antN = NULL;
    sNode* t = NULL;
    /* se a lista for vazia */
    if(ISNULL(l->first))
        return (0);
    /* se 'm' for igual 'n' */
    if(ISEQUAL(m, n)) 
        return (0);
    /* percorre todos o ligamentos ate null */
    for(t = l->first;!ISNULL(t);t = t->next){
        /* guardando os nós anteriores a 'm' e 'n' */
        if(ISEQUAL(t->next, m))antM = t;
        if(ISEQUAL(t->next, n))antN = t;
    }
    
    /* caso os nós sejam válidos */
    if(!ISNULL(m) && !ISNULL(n)){
        /* se o anterior a 'm' for diferente de nulo */
        if(!ISNULL(antM)){   
            /* antM aponta para 'n' */         
            antM->next = n;
        } else {
            /* caso contrario a cabeca da lista vira 'n' */
            l->first = n;
        }

        /* se o anterior a 'n' for diferente de nulo */
        if(!ISNULL(antN)){
            /* antN aponta para 'm' */   
            antN->next = m;
        }else{
            /* caso contrario a cabeca da lista vira 'm' */
            l->first = m;
        }
        /* t recebe o nodo onde 'm' aponta */
        t = m->next;
        /* 'm' aponta para onde 'n' apontava */
        m->next = n->next;
        /* 'n' aponta para onde 'm' apontava */
        n->next = t;

    }else{
        printf("swapping is not possible\n");
        return (0);
    }
    return (1);   

}

/* recupera um nodo em uma posicao especifica */
sNode* sAtPosition(sList* n,int i){
    sNode* p;
    int aux = 0;
    for (p = n->first;!ISNULL(p);p = p->next){
        if(ISEQUAL(aux, i)){
            return p;
        }
        aux++;
    }
    printf("index not found\n");
    return NULL;    
}

/* recupera o tamanho de uma lista */
int sGetSize(sList* n){
    
    int i = 0;
    sNode* p;
    
    if(ISNULL(n->first)){
        sListException(EMPTY);
        return (0);
    }
    
    for (p = n->first;!ISNULL(p);p = p->next)i++;
    return i;
}

/* retorna o ponteiro para o menor valor da lista se encontrado ou NULL */
sNode* findMin(sNode* l){
    sNode *p, *min = l;
    for(p = l;!ISNULL(p);p = p->next)
        if(p->value < min->value) min = p;
    return min;
}

/* buble sort para a ordenacao dos valores em uma lista simplesmente encadeada */
int sBubbleSort(sList* n, int size, int sortType){

    sNode *p, *q;
    int i;
    
    if(ISNULL(n->first)){
        sListException(EMPTY);
        return (0);
    }

    if(size < 1) return (1);

    for(i = 0; i < size; i++){
        p = sAtPosition(n, i);
        q = sAtPosition(n, i+1);
        if(ISNULL(p)||ISNULL(q))break;
        
        switch (sortType)
        {
            case CRESCENT:{
                if(p->value > q->value)
                    sSwapValue(p, q);
            }break;
            case DECRESCENT:{
                if(p->value < q->value)
                    sSwapValue(p, q);
            }break;        
            default:{
                printf("order type not defined\n");
                return (0);
            }break;
        }
            
    }

    return sBubbleSort(n, size-1, sortType);

}
/* Move o menor elemento para o topo da lista */
void moveLess(sList* l){
    sNode *aux , *antMin, *min, *p;
    min = findMin(l->first);
    if(ISEQUAL(min, l->first)){
        return;
    }
    /* O(n) */
    for(p = l->first;!ISNULL(p);p = p->next){
        if(ISEQUAL(p->next, min)){
            antMin = p;
            break;
        }
    }
    aux = min->next;
    min->next = l->first;
    antMin->next = aux;
    l->first = min; /* nova cabeca da lista */
}
/* limpa a lista da memoria */
void destroyList(sList* l){
    sNode *p, *aux = NULL;
    p = l->first;
    while(!ISNULL(p)){
        aux = p;
        p = p->next;
        free(aux);
    }
    l->first = NULL;
}
/* informa os valores */
int sInfoList(sList* n){

    sNode* p;

    if(ISNULL(n->first)){
        printf("sNode null pointer!\n");
        return (0);
    }

    for(p = n->first;!ISNULL(p);p=p->next)
        printf("%d\n", p->value);
        
    printf("\n");
    return (1);
}

#endif

