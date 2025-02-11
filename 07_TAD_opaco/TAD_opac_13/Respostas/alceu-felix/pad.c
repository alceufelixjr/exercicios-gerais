#include "pad.h"
#include <stdio.h>
#include <stdlib.h>

// typedef struct pad{ 
//     int qtdpacientes; /**< A quantidade de pacientes no PAD. */
//     tPaciente* listapacientes[100]; /**< A lista de pacientes do PAD. */
// } tPad;

/**
 * @brief Cria um novo PAD.
 * 
 * @return Retorna um ponteiro para a estrutura de dados tPad contendo o novo PAD criado.
 */
tPad* CriaPad()
{
    tPad *p = (tPad *) malloc (sizeof(tPad));
    p->listapacientes[100] = (tPaciente *) malloc (sizeof(tPaciente)); 

    return p;
}

/**
 * @brief Roda o PAD, permitindo que o usuário adicione pacientes e lesões.
 * 
 * @param p Ponteiro para a estrutura de dados tPad contendo o PAD a ser rodado.
 */
void RodaPad(tPad *p)
{
    char op;
    int qtdPacientes = 0;

    while(1)
    {
        scanf("%c\n",&op);
        if(op == 'P' && qtdPacientes < 100)
        {
            LePaciente(p->listapacientes[qtdPacientes]);
            qtdPacientes++;            
        }
        else if(op == 'L')
        {
            tLesao *lesao = (tLesao *) malloc (sizeof(tLesao)); 
            LeLesao(lesao);
        }
        else if(op == 'F')
            exit(1);
    }
}

/**
 * @brief Imprime um relatório com as informações dos pacientes e lesões do PAD.
 * 
 * @param p Ponteiro para a estrutura de dados tPad contendo o PAD a ser impresso.
 */
void ImprimeRelatorioPad(tPad *p);

/**
 * @brief Libera a memória alocada para uma estrutura de dados tPad.
 * 
 * @param p Ponteiro para a estrutura de dados tPad a ser liberada.
 */
void LiberaPad(tPad *p)
{
    for(int i = 0; i < 100; i++)
    {
        free(p->listapacientes[i]);
    }
    free(p);
}

