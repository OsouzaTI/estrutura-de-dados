#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main(){
    int *ptr, i;
    ptr = (int*)malloc(MAX * sizeof(int));
    for (i = 0; i < MAX; i++)
        ptr[i] = 10;
    
    for (i = 0; i < MAX; i++)
        printf("%d\n", ptr[i]);

    return 0;
}