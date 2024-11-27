#include "data.h"
#include <stdio.h>
#include "constantes.h"



int verificaDataValida(int dia, int mes, int ano)
{
    if(dia > numeroDiasMes(mes,ano))
        return 0;
    if(mes > NUM_MESES)
        return 0;
    return 1;
}

void imprimeData(int dia, int mes, int ano)
{
    printf("%02d/%02d/%04d\n", dia, mes, ano);
}

void imprimeMesExtenso(int mes)
{
    mes--; //como indice de char comeca no 0...
    char meses[NUM_MESES][MAX_CHAR_MESES] = {"Janeiro", "Fevereiro", "Marco", "Abril", 
    "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    for (int i = 0; i <= mes; i++)
    {
        if(i == mes)
        {
            printf("%s", meses[i]); //Nao eh necessario explicitar max_char_meses
        }
    }
}

void imprimeDataExtenso(int dia, int mes, int ano)
{
    printf("%02d de ",dia);
    imprimeMesExtenso(mes);
    printf(" de %04d\n",ano);
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
                return 29;
            return 28;
        }
        if(!(mes%2))
            return 30;
        return 31;
    }
    else if(mes > 7)
    {
        if(!(mes%2))
            return 31;
        return 30;
    }
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    if(ano2 > ano1)
        return -1;
    if(ano1 > ano2)
        return 1;
    if(ano1 == ano2)
    {
        if(mes2 > mes1)
            return -1;
        if(mes1 > mes2)
            return 1;
        if(mes1 == mes2)
        {
            if(dia2 > dia2)
                return -1;
            if(dia1 > dia2)
                return 1;
            return 0;
        }   
    }   
}

int calculaDiasAteMes(int mes, int ano)
{
    int countDias = 0;
    for (int i = 0; i < mes; i++)
    {
        countDias += numeroDiasMes(i, ano);
    }
    return countDias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    int dias1 = dia1 + calculaDiasAteMes(mes1, ano1) + (ano1 - 1) * 365;
    for (int i = 0; i < ano1;i++)
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

    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1)
        return dias1 - dias2;
    if(comparaData(dia1,mes1,ano1,dia2,mes2,ano2) == -1)
        return dias2 - dias1;
    if(!comparaData(dia1,mes1,ano1,dia2,mes2,ano2))
        return 0;
}

void imprimeProximaData(int dia, int mes, int ano)
{
    if(dia == numeroDiasMes(mes,ano))
    {
        if(mes == 12)
            printf("%02d/%02d/%04d", 1, 1, ano+1);
        if(mes < 12)
            printf("%02d/%02d/%04d", 1, mes+1, ano);
    }
    else
    {
        printf("%02d/%02d/%04d", dia+1, mes, ano);
    }
}