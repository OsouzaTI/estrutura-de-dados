#include <stdio.h>

const int n = 10;

int fib(int a, int b, int cont){
    if(cont >= n)return b;
    return fib(b, a + b, cont + 1);
}

int main(void)
{
    int n1, n2, aux;
    n1 = 0;
    n2 = 1;    
    printf("fib de %d = %d\n", n, fib(n1, n2, 0));
    return 0;
}