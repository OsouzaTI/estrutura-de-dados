#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i;
    char *t = "ola";
    i = atoi(t);
    printf("ERROR: %d\n", i);
    return 0;
}