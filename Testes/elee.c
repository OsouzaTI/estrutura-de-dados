#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "");
    char msg[1024];
    printf("Mensagem: ");
    scanf("%s", &msg);
    if(strlen(msg)>0){
        printf("\n SIM ELE É!\n");
    }
    system("pause");
    return 0;
}