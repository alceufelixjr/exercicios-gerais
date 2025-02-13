#include "banco.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    tBanco *banco = CriaBanco();
    
    char op;
    while(1)
    {
        scanf("%c\n",&op);
        if(op == 'A')
            AbreContaBanco(banco);
        else if(op == 'S')
            SaqueContaBanco(banco);
        else if(op == 'T')
            TransferenciaContaBanco(banco);
        else if(op == 'R')
            ImprimeRelatorioBanco(banco);
        else if(op == 'D')
            DepositoContaBanco(banco);
        else if(op =='F')
            break;
    }
    DestroiBanco(banco);
    return 0;
}