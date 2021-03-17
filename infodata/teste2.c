#include <stdio.h>
#include <stdlib.h>
#include "infodata.h"

#define MAX 100

int main(void)
{

    char *nomes[] = {
        "ozeias",
        "pedro",
        "mamaco",
        "Opa"
    };

    sDoublePointerCData(nomes, 3, MAX);

    return 0;
}