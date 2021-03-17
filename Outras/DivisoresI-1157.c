#include <stdio.h>

int main(){
    int i = 0, N;
    scanf("%d", &N);
    while(++i <= N)
        if((N%i)==0) printf("%d\n", i);
    return 0;
}