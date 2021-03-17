#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE_STRING 100

int main(void)
{
    char entrada[MAX_BUFFER_SIZE_STRING];
    while(1){
        while(fgets(entrada, MAX_BUFFER_SIZE_STRING, stdin)!=NULL){
            printf("==============================\n");
            printf("value: %s\n", entrada);
            printf("length: %d\n", strlen(entrada));
            printf("bytes: %d\n", sizeof(entrada));
            printf("==============================\n");
        };
        break;
    }
    return 0;
}