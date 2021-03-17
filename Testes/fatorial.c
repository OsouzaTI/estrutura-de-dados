#include <stdio.h>

int fat(int n){return n==1? 1: n*fat(n-1);}

int main(void)
{
    printf("fatorial de 5: %d", fat(5));
    return 0;
}