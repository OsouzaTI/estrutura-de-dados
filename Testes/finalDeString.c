#include <stdio.h>
#include <stdlib.h>
#define MAX 30

void printaString(char* ptrStr){
    int i = -1;
    while(ptrStr[++i] != '\0')
        printf("%c", *(ptrStr+i));
    printf("\n");
}

int main(void)
{
    char* str0 = "Digite seu nome: \0 sadasdasdas";
    char* str1 = "O nome recebido foi: \0dfsdfsdfsfsd";    
    int i = -1;
    char *ptrNome = (char*)malloc(MAX*sizeof(char));
    printaString(str0);
    scanf("%s", ptrNome);
    printaString(str1);
    printaString(ptrNome);   
    return 0;
}