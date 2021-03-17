#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, x;
    scanf("%d", &n);
    do
    {        
        scanf("%d", &x);
        int i = 1, d = 0;
        for (i = 1; i < x; i++)        
            if(!(x%i))d+=i;                  
        if(x==d)printf("%d eh perfeito\n", x);
        else printf("%d nao eh perfeito\n", x);
    } while (--n > 0);
}