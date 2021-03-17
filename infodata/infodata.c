#include "infodata.h"

void sSinglePointerData(int* data){
    int i = 0;
    while(*data+i++){
        printf("data[%d] -> %d\n", i, data[i]);
    }
}

void sDoublePointerData(int** data, int rows, int cols){
    int *aux;
    for (int i = 0; i < rows; i++)
    {
        printf("data[%p]: \n", (data+i));
        printf("\t sizeof: %d\n", sizeof(*(data+i))*cols);
        for (int j = 0; j < cols; j++)
        {
            aux = *(data+i)+j;
            printf("\t value[%p] : %d\n", aux, *aux);
        }        
    }    
}

void sDoublePointerCData(char** data, int rows, int cols){
    int size = 0; char *aux;
    for (int i = 0; i < rows; i++)
    {
        size = 0;
        printf("size of data: %d bytes\n", sizeof(data)*rows);
        printf("data[%p]: \n", (data+i));
        for (int j = 0; j < cols; j++)
        {
            aux = *(data+i)+j;
            if(*aux == '\0')break;
            printf("\t value[%p] : %c\n", aux, *aux);
            size++;
        } 
        printf("\t sizeof: %d bytes\n", sizeof(**(data+i))*size);
    }    
}
