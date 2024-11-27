#include <stdio.h>
#include "temperature_conversor.h"



int main(void)
{
    int DEBUG = 1; //0 desativa 
    float temp;
    char op;
    scanf("%d\n", &temp);

    while(1)
    {
        scanf("%c\n",&op);
        if(op == 99) // letra 'c'
        {
            scanf("%c", &op);
            if(op == 102)
            {
                
            }
            else if(op == 107)
            {

            }
            
        }
        else if(op == 102)// letra 'f'
        {

        }
        else if(op == 107)//letra 'k'
        {

        }
        
    }
    return 0;
}