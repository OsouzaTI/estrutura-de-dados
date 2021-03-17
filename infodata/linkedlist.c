#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "infodata.h"

#define MAX_BUFFER_SIZE_STRING 100

struct List {
    char** data;
    int size;
    int lastIndex;
} typedef List;

void inicialization(List* list){
    list->data = (char**)malloc(sizeof(list->data));
    list->size = 0;
    list->lastIndex = -1;
}

void realocation(List* list){
    list->data = (char**)realloc(list->data, ++list->size * sizeof(list->data));
    list->lastIndex++;
}

void insert(List* list, char* value){
    realocation(list); // aloca mais um espaco na memoria
    *(list->data+list->lastIndex) = (char*)malloc(strlen(value)*sizeof(char));
    strcpy(*(list->data+list->lastIndex), value);
}

void destroy(List* list){
    for (int i = 0; i < list->size; i++)
        free(*(list->data+i));
}

int main(void)
{
    int size = 1;
    List list;
    inicialization(&list);
    char entrada[MAX_BUFFER_SIZE_STRING];    
    while(1){
        gets(entrada);
        if(*entrada == '\0'){
            break;
        }
        insert(&list, entrada);
        sDoublePointerCData(list.data, list.size, MAX_BUFFER_SIZE_STRING);
    }
    destroy(&list);
    return 0;
}