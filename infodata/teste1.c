#include <stdio.h>
#include <stdlib.h>
#include "infodata.h"
#define MAX 5

void limpar(int** data){
    for (int i = 0; i < MAX; i++)
        free(data[i]);
    free(data);    
}

int main(void)
{
    int** data = (int**)malloc(MAX * sizeof(int));
    for (int i = 0; i < MAX; i++){       
        *(data+i) = (int*)malloc((MAX+1) * sizeof(int));
        for (int j = 0; j < MAX; j++)
            *(*(data+i)+j) = rand()%30;
        
    }
    sDoublePointerData(data, MAX, MAX);
    limpar(data);
    return 0;
}