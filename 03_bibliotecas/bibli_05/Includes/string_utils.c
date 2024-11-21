#include "string_utils.h"
#include <string.h>

int string_length(char *str)
{
    int i = 0; 
    int count = 1;

    while(1)
    {
        if((str[i] == '\0'))
        {
            count++;
            break;
        }
        i++;
        count++;
    }
    return count;
}