#include <stdio.h>

long long int fatorial(int n){
    if(n > 1) return n * fatorial(n-1);    
    if(!n) return 1;
    return n;
}

int main(void)
{  
    int f1, f2;
    while(scanf("%d %d", &f1, &f2) != EOF)
        printf("%lld\n", fatorial(f1) + fatorial(f2));
    return 0;
}