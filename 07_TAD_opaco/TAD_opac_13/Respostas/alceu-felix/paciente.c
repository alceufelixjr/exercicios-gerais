#include "paciente.h"
#include <stdio.h>
#include <stdlib.h>

struct paciente{
    char * nome;
    tData* nascimento;
    char * cartaoSus;
    char genero;
    tLesao**  listaLesao;
    int qtdLesoes;
    int maxLesoes;
};

/**
 * @brief Retorna o número do cartão SUS do paciente.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @return Retorna uma string contendo o número do cartão SUS do paciente.
 */
char* GetCartaoSusPaciente(tPaciente* p)
{
    return p->cartaoSus;
}

/**
 * @brief Retorna a quantidade de lesões do paciente.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @return Retorna a quantidade de lesões do paciente.
 */
int GetQtdLesoesPaciente(tPaciente* p)
{
    return p->qtdLesoes;
}

/**
 * @brief Retorna a quantidade de cirurgias necessárias para tratar as lesões do paciente.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @return Retorna a quantidade de cirurgias necessárias para tratar as lesões do paciente.
 */
int GetQtdCirurgiasPaciente(tPaciente* p)
{
    int qtdCirurgias = 0;
    for(int i = 0;i < p->qtdLesoes; i++)
    {
        if(PrecisaCirurgiaLesao(p->listaLesao[i]))
        {
            qtdCirurgias++;
        }
    }
    return qtdCirurgias;
}

/**
 * @brief Retorna a data de nascimento do paciente.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @return Retorna a data de nascimento do paciente.
 */
tData* GetNascimentoPaciente(tPaciente* p)
{
    return p->nascimento;
}

/**
 * 
 * @brief Cria uma estrutura do tipo tPaciente
 * 
 * @return Retorna um ponteiro para a estrutura de dados tPaciente
 * 
 */
tPaciente* CriaPaciente()
{
    tPaciente *p = (tPaciente *) malloc (sizeof(tPaciente));
    p->nome = (char *) malloc (sizeof(char)*TAM_NOME);
    //p->nascimento = CriaData();
    p->cartaoSus = (char *) malloc (sizeof(char)*TAM_CSUS);
    p->listaLesao = (tLesao **) malloc (sizeof(tLesao*));

    return p;
}

/**
 * @brief Lê informações sobre um paciente do usuário.
 * 
 * @return Retorna um ponteiro para a estrutura de dados tPaciente contendo as informações lidas.
 */
void LePaciente(tPaciente* p)
{
    scanf("%[^\n]\n",p->nome);
    p->nascimento = LeData();
    scanf("%[^\n]\n",p->cartaoSus);
    scanf("%c\n",&p->genero);
    p->maxLesoes = QTD_LESAO;
}

/**
 * @brief Imprime as informações de um paciente na saída padrão.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 */
void ImprimePaciente(tPaciente* p)
{
    if(p->qtdLesoes > 0)
    {
        printf(" - %s - ",p->nome);
        for(int i = 0; i < p->qtdLesoes; i++)
        {
            printf("%s ",GetIdLesao(p->listaLesao[i]));
        }
        printf("\n");
    }
}

/**
 * @brief Libera a memória alocada para uma estrutura de dados tPaciente.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente a ser liberada.
 */
void LiberaPaciente(tPaciente* p)
{
    if(p != NULL)
    {
        for(int i = 0; i < p->qtdLesoes; i++)
        {
            free(p->listaLesao[i]);
        }
        free(p->listaLesao);
        free(p->nome);
        // free(p->nascimento); USA LIBERADATA NAO FREE NO p->NASCIMENTO
        LiberaData(p->nascimento);
        free(p->cartaoSus);
        free(p);
    }
}


/**
 * @brief Adiciona uma lesão à lista de lesões do paciente.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @param l Ponteiro para a estrutura de dados tLesao contendo as informações da lesão.
*/
void AdicionaLesaoPaciente(tPaciente* p, tLesao* l)
{
    p->listaLesao[p->qtdLesoes] = l;
}

