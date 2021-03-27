#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fatorial(int n){
    int i, fat = n;
    for (i = n; i > 1; i--)
        fat *= i - 1;
    return fat;
}

int main(void)
{
    while(1){
        int i, k = 0, resultado = 0;
        char *digitos = (char*)malloc(5*sizeof(char));
        scanf("%s", digitos);
        if(*digitos == '0')exit(0);
        k = strlen(digitos);
        for (i = 0; i < k; i++){
            char aux = *(digitos+i);
            resultado += atoi(&aux) * fatorial(k-i);
        }
        printf("%d\n", resultado);  
        free(digitos);  
    }
    return 0;
}