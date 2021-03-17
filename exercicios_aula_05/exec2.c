#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarStrings(char** lista, int tamanho){
    char *aux;  /* variavel auxiliar */
    for(int i = 0; i < tamanho; i++){
        aux = *(lista+i);
        printf("%s\n", aux);
    }
}

void destruirPonteiros(char** lista, int tamanho){
    /* limpando cada array de char alocado dinamicamente */
    for(int i = 0; i < tamanho; i++)
        free(*(lista+i));
    /* limpando a lista como um array de ponteiros */
    free(lista);
}

void realocagemDeBytes(char*** ptrList, int newSize){
    /* alocando memoria para a primeira entrada */
    if(newSize <= 1){
        *ptrList = malloc(newSize * sizeof(char*));
        return;
    }
    /* realocando memoria para as demais entradas */
    *ptrList = (char**)realloc(*ptrList, newSize * sizeof(char*));    
}

int main(void)
{
    int strSize = 0; /* controle de quantas strings ja foram alocadas */
    char **strings; /* lista principal */
    char entrada[100]; /* entrada com 100bytes de buffer */
    while(1){
        gets(entrada);
        if(*entrada == '\0'){
            mostrarStrings(strings, strSize);
            break;                    
        }
        strSize++; /* incrementa a quantidade de strings */ 
        realocagemDeBytes(&strings, strSize);
        int tam = strlen(entrada);
        /* na posicao strings[strSize-1] aloca o suficente + 1 de margem */
        *(strings+(strSize-1)) = (char*)malloc((tam+1)*sizeof(char));
        /* copia da entrada pro array alocado */
        strcpy(*(strings+(strSize-1)), entrada);       
    }
    destruirPonteiros(strings, strSize);
    return 0;
}