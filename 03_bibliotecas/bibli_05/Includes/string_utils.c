#include "string_utils.h"
#include <string.h>

int string_length(char *str)
{
    int count = 1;
    while(strcmp(str,"\0") != 0)
    {
        str++;
        count++;
    }
}