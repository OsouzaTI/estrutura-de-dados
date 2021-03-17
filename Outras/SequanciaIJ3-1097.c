#include <stdio.h>
int main(void)
{
    int i, j, l = 1, n;
    for (i = 0; i < 9; i+=2){
        l *= -1;
        n = 7 + i;
        for (j = 0; j < 3; j++){
            int aux = n;
            aux -= j;
            printf("I=%d J=%d\n", i+1, aux);    
        }    
    }
    return 0;
}