#include <stdio.h>
#include "data.h"
#include "constantes.h"

int verificaDataValida(int dia, int mes, int ano)
{
    if(!ano)
        return 0;
    if(mes > 12 || !mes)
        return 0;
    if(dia > numeroDiasMes(mes,ano))
        return 0;
    return 1;
}

void imprimeMesExtenso(int mes)
{
    mes--;
    char meses[NUM_MESES][TAM_NOME_MES] = {"Janeiro","Fevereiro","Marco","Abril","Maio",
    "Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};
    for (int i = 0; i < NUM_MESES;i++)
    {
        if(i == mes)
        {
            printf("%s", meses[i]);
        }
    }
}

void imprimeDataExtenso(int dia, int mes, int ano)
{
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %04d", ano);
}

int verificaBissexto(int ano)
{
    if(!(ano%4) && ano%100)
        return 1;
    if(!(ano%400))
        return 1;
    return 0;
}

int numeroDiasMes(int mes, int ano)
{
    if(mes <= 7)
    {
        if(mes == 2)
        {
            if(verificaBissexto(ano))
            {
                return 29;
            }
            return 28;
        }
        if(!(mes%2))
        {
            return 30;
        }
        return 31;
    }
    if(mes > 7)
    {
        if(!(mes%2))
        {
            return 31;
        }
        return 30;    
    }
        
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    if(ano1 == ano2)
    {
        if(mes1 == mes2)
        {
            if(dia1 == dia2)
            {
                return 0;
            }    
            if(dia1 > dia2)
            {
                return 1;
            }
            return -1;
        }
        if(mes1 > mes2)
        {
            return 1;
        }
        return -1;
    }
    if(ano1 > ano2)
    {
        return 1;
    }
    return -1;
}

int calculaDiasAteMes(int mes, int ano)
{
    int dias = 0;
    for (int i = 1; i < mes; i++)
    {
        dias += numeroDiasMes(i, ano);
    }
    return dias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    
        int dias1 = dia1 + calculaDiasAteMes(mes1, ano1) + (ano1 - 1) * 365;
        for (int i = 0; i < ano1; i++)
        {
            if(verificaBissexto(i))
                dias1++;
        }

        int dias2 = dia2 + calculaDiasAteMes(mes2, ano2) + (ano2 - 1) * 365;
        for (int i = 0; i < ano2; i++)
        {
            if(verificaBissexto(i))
                dias2++;
        }
    if(comparaData(dia1,mes1,ano1,dia2,mes2,ano2) == 1)
    {
        return dias1 - dias2;
    }
    if(comparaData(dia1,mes1,ano1,dia2,mes2,ano2) == -1)
    {
        return dias2 - dias1;
    }
    if(!comparaData(dia1,mes1,ano1,dia2,mes2,ano2))
        return 0;
}

