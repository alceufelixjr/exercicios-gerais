#include "string_utils.h"
#include "constantes.h"
#include <string.h>
#include <stdio.h>

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

void string_copy(char *src, char *dest)
{
    int i = 0;
    while(1)
    {
        if(src[i] == '\0')
        {
            break;
        }
        else
        {
            dest[i] = src[i];
        }
        i++;
    }
}


void string_upper(char *str)
{
    int i = 0;
    while(1)
    {
        if((str[i] == '\0'))
        {
            break;
        }else
        {
            if(str[i] >= 97)
                str[i] -= 32;
            i++;
        }     
    }
}

void string_lower(char *str)
{
    int i = 0;
    while(1)
    {
        if(str[i] == '\0')
        {
            break;
        }else
        {
            if(str[i] < 90 && str[i] >= 65)
            {
                str[i] += 32;
            }
            i++;
        }
    }
}

void string_reverse(char *str)
{
    
}