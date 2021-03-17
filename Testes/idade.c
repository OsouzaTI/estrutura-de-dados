#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    if(idade < 18){
        printf("Menor de idade\n");
    }else{
        printf("Maior de idade\n");
    }
    return 0;
}