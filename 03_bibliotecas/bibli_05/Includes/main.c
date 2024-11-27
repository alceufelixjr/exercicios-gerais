#include "string_utils.h"
#include <stdio.h>
#include "constantes.h"

int main(void)
{
    int DEBUG = 1; // 0 --> desativa print
    char str[MAX_STRING];
    char dest[MAX_STRING];
    scanf("%[^\n]", str);

    if(DEBUG)
        printf("SCANF --> %s\n", str);
    string_length(str);
    if(DEBUG)
        printf("STRING_LENGTH --> %d\n", string_length(str));
    string_copy(str, dest);
    if(DEBUG)
        printf("STRING_COPY --> %s\n", dest);
    string_upper(str);
    if(DEBUG)
        printf("STRING_UPPER --> %s\n", str);
    string_lower(str);
    if(DEBUG)
        printf("STRING_LOWER --> %s\n", str);
    string_reverse(str);
    if(DEBUG)
        printf("STRING_REVERSE --> %s\n", str);
}