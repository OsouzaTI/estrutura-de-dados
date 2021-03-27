#include <stdio.h>

int main(void)
{
    int N, a, b;
    scanf("%d", &N);     
    while(N > 0){
        scanf("%d %d", &a, &b);
        printf("%d cm2\n", (a*b)/2);  
        N--;      
    }
    return 0;
}