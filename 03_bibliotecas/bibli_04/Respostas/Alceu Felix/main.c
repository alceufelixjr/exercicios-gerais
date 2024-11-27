#include <stdio.h>
#include "constantes.h"
#include "data.h"
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

int main()
{
    Data data1;

    scanf("%d/%d/%d", &data1.dia, &data1.mes, &data1.ano);
    if(verificaDataValida(data1.dia, data1.mes, data1.ano) == 0)
    {
        printf("A data informada eh invalida");
        exit(1);
    }
    printf("\nData informada: ");
    imprimeDataExtenso(data1.dia, data1.mes, data1.ano);
    if(verificaBissexto(data1.ano))
        printf("O ano informado eh bissexto\n");
    else
        printf("O ano informado nao eh bissexto\n");
    printf("O mes informado possui %0d dias\n",numeroDiasMes(data1.mes,data1.ano));
    printf("A data seguinte eh: ");
    imprimeProximaData(data1.dia, data1.mes, data1.ano);
}