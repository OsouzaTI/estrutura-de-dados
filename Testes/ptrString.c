#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printar(char** data, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("[%d] -> %s\n", i, *(data+i));
    }
}

int main(void)
{
    int posicao = 0;
    char** ptrstring = NULL;
    ptrstring = (char**)malloc(sizeof(char*));
    char entrada[100];
    while(1){
        gets(entrada);
        if(*entrada == '\0')break;
        int len = strlen(entrada);
        *(ptrstring+posicao) = (char*)malloc(len*sizeof(char));
        strcpy(*(ptrstring+posicao), entrada);
        // aloca posicao+1 espacos
        posicao++; // controle de indice
        ptrstring = (char**)realloc(ptrstring, (posicao+1)*sizeof(char*));
    }
    printar(ptrstring, posicao);
    return 0;
}