#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rafael(char* res, int* k, int x, int y){
    int p = ((3*x)*(3*x)) + (y*y);
    if(p > *k){
        *k = p;
        strcpy(res, "Rafael ganhou");
    }
}

void beto(char* res, int* k, int x, int y){
    int p = 2*(x*x)+((5*y)*(5*y));
    if(p > *k){
        *k = p;
        strcpy(res, "Beto ganhou");
    }
}

void carlos(char* res, int* k, int x, int y){
    int p = -100*x+(y*y*y);
    if(p > *k){
        *k = p;
        strcpy(res, "Carlos ganhou");
    }
}

void resposta(int x, int y){
    int k = 0;
    char res[30];
    rafael(res, &k, x, y);
    carlos(res, &k, x, y);
    beto(res, &k, x, y);
    printf("%s\n", res);
}

int main(void)
{
    int N;
    int x, y, r, b, c;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &x, &y);
        resposta(x, y);
    }   
    
    return 0;
}