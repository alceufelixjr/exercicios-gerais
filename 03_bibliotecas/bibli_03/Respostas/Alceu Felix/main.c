#include <stdio.h>
#include "data.h"

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

int main(void)
{
    Data data1, data2;
    int comparador; //pegar inteiro do comparaData
    int diferencaDias; //pegar inteiro de calculaDiferencaDias
    scanf("%02d/%02d/%04d",&data1.dia,&data1.mes,&data1.ano);
    scanf("%02d/%02d/%04d",&data2.dia,&data2.mes,&data2.ano);

    if (!verificaDataValida(data1.dia,data1.mes,data1.ano) || !verificaDataValida(data2.dia,data2.mes,data2.ano))
    {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 0;
    }
        
    printf("Primeira data: ");
    imprimeDataExtenso(data1.dia, data1.mes, data1.ano);
    printf("\n");
    printf("Segunda data: ");
    imprimeDataExtenso(data2.dia, data2.mes, data2.ano);
    printf("\n");

    comparador = comparaData(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
    if(comparador == -1)
    {
        printf("A primeira data eh mais antiga\n");
    }   
    if(comparador == 1)
    {
        printf("A segunda data eh mais antiga\n");
    }
    if(!comparador)
    {
        printf("As datas sao iguais\n");
    }


    //diferencaDias = calculaDiferencaDias(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
    //printf("A diferenca em dias entre as datas eh: %02d dias\n", diferencaDias);
    return 0;
}