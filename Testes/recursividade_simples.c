#include <stdio.h>

void funcao(int n){
    printf("%d\n", n);
    return funcao(++n);
}

int main(){
    funcao(0);
    return 0;
}