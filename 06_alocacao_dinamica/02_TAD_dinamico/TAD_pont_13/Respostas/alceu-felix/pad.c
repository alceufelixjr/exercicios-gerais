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
    tPad *pd = (tPad*) malloc (sizeof(tPad));
    pd->qtdpacientes = 0;

    return pd;
}

/**
 * @brief Roda o PAD, permitindo que o usuário adicione pacientes e lesões.
 * 
 * @param p Ponteiro para a estrutura de dados tPad contendo o PAD a ser rodado.
 */
void RodaPad(tPad *p)
{
    char op;

    while(1)
    {
        scanf("%c\n",&op);
        if(op == 'P')
        {
            tPaciente *pac = CriaPaciente();
            LePaciente(pac);
            
            if(p->qtdpacientes < 100)
            {
                p->listapacientes[p->qtdpacientes] = pac;
                p->qtdpacientes++;
            }
        }
        else if(op == 'L')
        {
            tLesao *les = CriaLesao();
            LeLesao(les);
        }
        else if(op == 'F'){}
        else
        {
            printf("ERRO!\n");
            exit(1);
        }
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
void LiberaPad(tPad *p);
