#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ISNULL(x)  (x == NULL)
#define ISEQUAL(x, y) (x == y)
// node list
typedef struct nList
{
    int value;
    struct nList* next;    
} nList;

void    createNodeList(nList** n);
int     isListNull(nList* n);
void    insertAtBegin(nList** n, int v);
void    insertAtEnd(nList** n, int v);
int     insertAtPosition(nList** n, int v, int pos);
int     removeEnd(nList** n);
int     removeAtPosition(nList* n, int key);
nList*  atPosition(nList* n,int i);
int     swapNodes(nList** l, nList* m, nList* n);
void    moveLess(nList** l);
void    infoNdList(nList* n);
void    destroyList(nList** lista);

int main(){

    nList* lista1 = NULL;
    nList* lista2 = NULL;

    clock_t t;

    for(int i = 0 ; i < 1000; i++)
        insertAtEnd(&lista1, rand()%1000);

    infoNdList(lista1);
    printf("\n movendo ponteiros \n");
    
    t = clock();   
    moveLess(&lista1);
    t = clock() - t;
    printf(
        "the nodes has swapped in %lf\n",
        ((double)t)/(CLOCKS_PER_SEC/1000)
    );        
    infoNdList(lista1);
    destroyList(&lista1);
    return 0;

}

/* 
*   FUNCTIONS 
*/

void createNodeList(nList** n){
    *n = (nList*)malloc(sizeof(nList));
    (*n)->next = NULL;
}

int isListNull(nList* n){
    if(ISNULL(n)){
        printf("Lista nula!\n");
        return (1);
    }
    return (0);
}

void insertAtBegin(nList** n, int v){
    /* cria um novo nodo */
    nList* newlist;
    createNodeList(&newlist);
    newlist->value = v;
    /* novo nodo aponta para o primeiro elemento */
    newlist->next = *n;
    /* nova cabeca da lista */
    *n = newlist;
}

void insertAtEnd(nList** n, int v){
    nList* newlist;
    createNodeList(&newlist);
    newlist->value = v;
    newlist->next = NULL;
    
    /* caso seja o primeiro elemento */
    if(ISNULL(*n)){
        *n = newlist;
        return;
    } 

    nList* p; /* iterador do ponteiro */
    for(p = *n;p;p = p->next) /* percorre ate o fim */
        if(ISNULL(p->next))break;    
    p->next = newlist; /* adiciona no fim */
}


int insertAtPosition(nList** n, int v, int pos){
    if(isListNull(*n))return (0);

    nList* newlist;
    createNodeList(&newlist);
    newlist->value = v;
        
    int i = 0;
    nList *p, *q;
    for(p = *n;p;p = p->next){
        if(ISEQUAL(i, pos))break;
        i++;
        q = p;
    }

    q->next = newlist;
    newlist->next = p;

    return (1);
}

int removeEnd(nList** n){    
    if(isListNull(*n))return (0);

    if(ISNULL((*n)->next)){
        printf("item %d removed\n", (*n)->value);
        free(*n);
        *n = NULL;
        return (1);
    }

    nList *p, *q;
    for(p = *n;p;p = p->next){
        if(ISNULL(p->next)) break;
        q = p;
    }
    printf("item %d removed\n", p->value);
    free(q->next);
    q->next = NULL;
    return (1);
}

int removeAtPosition(nList* n, int key){
    unsigned char keyExists = 0;
    nList *p, *q;

    if(isListNull(n))return (0);

    for(p = n;p;p = p->next){
        if(ISEQUAL(p->value, key)){
            keyExists = 1;
            break;
        }
        q = p;
    }

    /* caso não encontre a chave de busca */
    if(!keyExists){
        printf("key %d not found", key);
        return (-1);
    }

    q->next = p->next;
    printf("removed { key: %d,  value %d }", key, p->value);
    free(p);

    return (1);

}

/* recupera um nodo em uma posicao especifica */
nList* atPosition(nList* n,int i){
    nList* p;
    int aux = 0;
    for (p = n;p;p = p->next){
        if(ISEQUAL(aux, i)){
            return p;
        }
        aux++;
    }
    printf("indice não encontrado!\n");
    return NULL;    
}

int swapNodes(nList** l, nList* m, nList* n){

    nList* antM = NULL;
    nList* antN = NULL;
    nList* t = NULL;
    /* se a lista for vazia */
    if(*l == NULL)
        return (0);
    /* se 'm' for igual 'n' */
    if(m == n) 
        return (0);
    /* percorre todos o ligamentos ate null */
    for(t = *l;t;t = t->next){
        /* guardando os nós anteriores a 'm' e 'n' */
        if(t->next == m)antM = t;
        if(t->next == n)antN = t;
    }
    
    /* caso os nós sejam válidos */
    if(m != NULL && n != NULL){
        /* se o anterior a 'm' for diferente de nulo */
        if(antM != NULL){   
            /* antM aponta para 'n' */         
            antM->next = n;
        } else {
            /* caso contrario a cabeca da lista vira 'n' */
            *l = n;
        }

        /* se o anterior a 'n' for diferente de nulo */
        if(antN != NULL){
            /* antN aponta para 'm' */   
            antN->next = m;
        }else{
            /* caso contrario a cabeca da lista vira 'm' */
            *l = m;
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

nList* findMin(nList* l){
    nList *p, *min = l;
    for(p = l;p;p = p->next)
        if(p->value < min->value) min = p;
    return min;
}

/* O(2n) */
void moveLess(nList** l){
    nList *aux , *antMin, *min, *p;
    min = findMin(*l); /* O(n) */
    /* O(n) */
    for(p = *l;p;p = p->next){
        if(p->next == min){
            antMin = p;
            break;
        }
    }
    aux = min->next;
    min->next = *l;
    antMin->next = aux;
    (*l) = min; /* nova cabeca da lista */
}

void infoNdList(nList* n){
    if(isListNull(n))return;
    nList *p;
    for(p = n;p;p = p->next)
        printf("n : %d\n", p->value);
}

void destroyList(nList** lista){
    nList *p, *aux = NULL;
    p = *lista;
    while(!ISNULL(p)){
        aux = p;
        p = p->next;
        free(aux);
    }
    *lista = NULL;
}

