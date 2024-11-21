#include "string_utils.h"
#include <stdio.h>


int main(void)
{
    char nome[] = {"Hello World!"};

    int i = string_length(nome);
    printf("%d\n", i);

    return 0;
}