#include <stdio.h>
#include <stdlib.h>

void caminhos(int* fib, int a, int b, int n){
    if(n > 0){
        return caminhos(fib, b, a + b, n-1);
    }
    *fib = a;
}

int main(void)
{

    while(1){
        int N, nCaminhos = 0;        
        scanf("%d", &N);
        if(N == 0) break;
        caminhos(&nCaminhos, 1, 1, N);
        printf("%d\n", nCaminhos);
    }   

    return 0;
}