#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node * prox;
    struct node * ant;
}Nodedup;

//estrutura de controle - ter controle dos ponteiros de controle
typedef struct listaDupla{
    Nodedup* inicio;
    Nodedup* fim;
}ListaDup;

//Operações 
ListaDup* criarListaDup(){
    ListaDup* l = (ListaDup*)malloc(sizeof(ListaDup));
    l->inicio = NULL;
    l->fim    = NULL;

    return l;
}
Nodedup* criarNoDup(int val){
    Nodedup* p = (Nodedup*)malloc(sizeof(Nodedup));
    p->valor = val;
    p->prox = NULL;
    p->ant = NULL;

    return p;
}
int listEstaVazia(ListaDup* l){
    return (l->inicio == NULL);
    /* outra forma mais simples de fazermos
    if(l->inicio == NULL)
        return 1;
    else
        return 0;*/   
}

void inserirInicioLista(ListaDup* l, int val){
    //comeca criando nó
    Nodedup* p = criarNoDup(val);

    //caso 1: lista esta vazia
    if(listEstaVazia(l)){
        l->inicio = p;
        l->fim = p;
    }
    else{ //lista possui elementos
        p->prox = l->inicio; //o final de p aponta para o inicio da nossa lista
        l->inicio->ant = p;
        l->inicio = p;
    }
}

void inserirFinalLista(ListaDup* l, int val){
    //comeca criando nó
    Nodedup* p = criarNoDup(val);
    p->valor = val;
    p->ant = l->fim;
    p->prox = NULL;
    if(l->fim != NULL){
        l->fim->prox = p;
    }else{
        l->inicio = p;
    }
    l->fim = p;
}

void imprimirLista(ListaDup* l){
    Nodedup* aux = l->inicio;
    printf("L : ");
    while(aux != NULL){
        printf("%d -> ",aux->valor);
        aux = aux->prox; //do inicio pro fim da lista
    }
    printf("NULL\n");
}

void imprimirListaInversa(ListaDup* l){
    Nodedup* aux = l->fim;
    printf("L : ");
    while(aux != NULL){
        printf("%d -> ",aux->valor);
        aux = aux->ant; //do fim pro inicio da lista
    }
    printf("NULL\n");
}

void removerLista(ListaDup* l, int val){
    Nodedup* p = l->inicio;
    //verifica se tem elementos para remover
    if(!listEstaVazia(l)){
        //caso 1: elemento esta no inicio
        if(l->inicio->valor == val){
            l->inicio = p->prox;
            if(l->fim = p){ //se tiver so 1 elemento
                l->fim = NULL;
            }else{
                l->inicio->ant = NULL;
            }
            free(p);
        } else{
            p = p->prox;
            while(p != NULL){
                if(p->valor == val){
                    printf("\nACHOU");
                    p->ant->prox = p->prox;
                    p->prox->ant = p->ant;
                    //break;  
                    free(p);  
                }
                 p = p->prox;
            }
        }
    }
}

void MoveMenor(ListaDup* l){
    if(!listEstaVazia(l)){
        Nodedup* p;
        Nodedup* min = l->inicio;
        for(p = l->inicio;p;p=p->prox){
            printf("%d - ", p->valor);
            if(p->valor < min->valor){
                min = p;
            }
        }
        
        printf("menor: %d\n", min->valor);
        printf("ant menor: %d\n", min->ant->valor);
        printf("prox menor: %d\n", min->prox->valor);
        min->ant->prox = min->prox;
        min->prox->ant = min->ant;      
        min->prox = l->inicio;
        l->inicio = min;
    }
    
}

int main(){
    ListaDup* L = criarListaDup();


    inserirFinalLista(L, 10);
    inserirFinalLista(L, 21);
    inserirFinalLista(L, 4);
    inserirFinalLista(L, 13);

    imprimirLista(L);
    
    MoveMenor(L);

    imprimirLista(L); //4 - 10 -21 -13

    
    return 0;
}


