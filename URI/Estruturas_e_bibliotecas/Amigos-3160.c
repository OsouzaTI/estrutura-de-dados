#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE_STRING 1024
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
    char *value;
    struct dNode *next;
    struct dNode *prev;
};

void createDlist(dList** l){
    (*l) = (dList*)malloc(sizeof(dList));
    (*l)->begin = NULL;
    (*l)->end = NULL;
}

dNode* createDnode(){
    dNode* n = (dNode*)malloc(sizeof(dNode));
    return n;
}

void dinsertAtBegin(dList* l, char *v){
    dNode* n = (dNode*)malloc(sizeof(dNode));
    n->value = (char*)malloc(sizeof(char)*(strlen(v)+1));
    strcpy(n->value, v);
    n->next = l->begin;
    n->prev = NULL;
    if(!ISNULL(l->begin))
        (l->begin)->prev = n;
    else
        l->end = n;
    l->begin = n;
}

void dinsertAtEnd(dList* l, char* v){
    dNode* n = createDnode();
    n->value = (char*)malloc(sizeof(char)*strlen(v));
    strcpy(n->value, v);
    n->prev = l->end;
    n->next = NULL;
    if(!ISNULL(l->end)){
        l->end->next = n;
    }else{
        l->begin = n;
    }
    l->end = n;
}

dNode* dsearchNode(dList* l, char *v){
    dNode* p;
    for(p = l->begin;p;p = p->next){
        if(strcmp(p->value, v)==0){
            return p;
        }
    }

    return NULL;
}

void printReverse(dList* l){
    dNode* p;
    for(p = l->end;p;p = p->prev){
        printf("%s", p->value);
        if(!ISNULL(p->prev)){
            printf(" ");
        }
    }
}   

void splitAndInsert(dList* l, char* nomes){
    char aux[BUFFER_SIZE_STRING];    
    /* simples split na string */
    int i = 0, j = 0;
    while(1){
        if(nomes[i] == (int)' '){
            aux[j] = '\0';
            dinsertAtBegin(l, aux);
            j = 0;
        }else{
            aux[j] = nomes[i];
            j++;
        }

        if(nomes[i+1] == '\0'){    
            aux[j] = '\0';        
            dinsertAtBegin(l, aux);
            break;
        }
        i++;
    }
}

int main(void)
{
    dList *listaA, *listaB,*final;
    createDlist(&listaA);
    createDlist(&listaB);
    createDlist(&final);
    char nomes[BUFFER_SIZE_STRING]; 
    char nomeAmigo[32];
    gets(nomes);  
    splitAndInsert(listaA, nomes);
    gets(nomes);  
    splitAndInsert(listaB, nomes);
    gets(nomeAmigo);  
    if(strcmp(nomeAmigo, "nao")==0){
        dNode* p;
        for(p = listaB->end;p;p=p->prev)
            dinsertAtBegin(listaA, p->value);
        printReverse(listaA);
    }else{
        dNode* p;
        dNode* amigo = dsearchNode(listaA, nomeAmigo);
        if(!ISNULL(amigo)){
            for(p = listaA->end;p;p = p->prev){
                if(p == amigo) break;
                dinsertAtBegin(final, p->value);
            }

            for(p = listaB->end;p;p = p->prev)
                dinsertAtBegin(final, p->value);

            for(p = amigo;p;p = p->prev)
                dinsertAtBegin(final, p->value);

            printReverse(final);
        }
    }
    printf("\n");
    return 0;
}