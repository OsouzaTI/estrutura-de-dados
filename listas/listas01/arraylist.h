#ifndef ARRAY_LIST
#define ARRAY_LIST

#define MAX_ARRAY_LIST 100
#define ISNULL(x) (x==NULL)
#define ISEQUAL(a, b)   (a == b)

#include <stdio.h>
#include <stdlib.h>

/* definicao da estrutura usada */
typedef struct Arraylist{
    int lenght;
    int data[MAX_ARRAY_LIST];
} Arraylist;

int createList(Arraylist** n){
    *n = (Arraylist*)malloc(sizeof(Arraylist));
    if(ISNULL(*n)){
        printf("erro na alocacao de memoria!\n");
        return (0);
    }
    (*n)->lenght = 0;
    return (1);    
}

int insert(Arraylist* n, int value){
    if(ISNULL(n)){
        printf("lista nula!\n");
        return (0);
    }
    n->data[n->lenght++] = value;
    return (1);
}

int insertAtPosition(Arraylist* n, int pos, int value){
    if(ISNULL(n)){
        printf("lista nula!\n");
        return (0);
    }

    if(pos > MAX_ARRAY_LIST){
        printf("posicao fora do limite maximo!\n");
        return (0);
    }

    n->data[pos] = value;
    n->lenght++;
    return (1);
}

Arraylist* arrayConcat(Arraylist *a, Arraylist *b){
    int i;
    Arraylist *result;
    createList(&result);

    for (i = 0; i < a->lenght; i++)
        insert(result, a->data[i]);
    for (i = 0; i < b->lenght; i++)
        insertAtPosition(result, a->lenght+i, b->data[i]);
    return result;
}

int divideArray(Arraylist* n, Arraylist** a, Arraylist** b){
    if(ISNULL(n)){
        printf("lista nula!\n");
        return (0);
    }else if(ISEQUAL(n->lenght, 0)){
        printf("lista vazia!\n");
        return (0);
    }else if(ISEQUAL(n->lenght,1)){
        printf("lista possui somente 1 elemento!\n");
        return (0);
    }

    int midN, i;

    free(*a);
    free(*b);
    createList(a);
    createList(b);

    midN = (int)(n->lenght/2);
    
    for(i = 0; i < midN; i++)
        insert(*a, n->data[i]);
    for(i = midN; i < n->lenght; i++)
        insert(*b, n->data[i]);

    return (1);
}

Arraylist* copyArray(Arraylist* n){
    if(ISNULL(n)){
        printf("lista nula!\n");
        return NULL;
    }
    int i;
    Arraylist* newArray;
    createList(&newArray);

    for(i = 0; i < n->lenght; i++)
        insert(newArray, n->data[i]);
    return newArray;
}

int searchKey(Arraylist* n, int key){
    if(ISNULL(n)){
        printf("lista nula!\n");
        return (0);
    }
    
    int existsKey = 0;
    int i;
    for(i = 0; i < n->lenght; i++){
        if(ISEQUAL(n->data[i], key)){
            existsKey = 1;
            return i;
        }
    }

    printf("chave nao encontrada!\n");
    return (-1);

}

int removeAtPosition(Arraylist* n, int position){

    if(ISNULL(n)){
        printf("fodase");
        return (0);
    }

    if(position > n->lenght){
        printf("posicao fora da memoria manipulada!\n");
        return (0);
    }

    int i;
    
    if(ISEQUAL(position, n->lenght)){
        n->data[position] = 0;   
        n->lenght--; 
        return (1);
    }

    if(ISEQUAL(position, 0)){
        for(i = 0; i < n->lenght; i++)            
            n->data[i] = n->data[i+1];
        n->lenght--;
        return (1);
    }
    
    for(i = position; i < n->lenght-1; i++)
        n->data[i] = n->data[i+1];
    n->lenght--;    
    return (1);

}

void infoArray(Arraylist* n){
    int i;
    for (i = 0; i < n->lenght; i++)
        printf("array[%d] -> %d\n", i, n->data[i]);
}

#endif