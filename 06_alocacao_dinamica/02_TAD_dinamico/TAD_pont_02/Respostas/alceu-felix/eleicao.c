#include "eleicao.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATOS_POR_CARGO 3
#define MAX_ELEITORES 10

// typedef struct {
//     tCandidato** presidentes;
//     int totalPresidentes;

//     tCandidato** governadores;
//     int totalGovernadores;

//     int votosBrancosPresidente;
//     int votosNulosPresidente;

//     int votosBrancosGovernador;
//     int votosNulosGovernador;

//     tEleitor** eleitores;
//     int totalEleitores;
    
// } tEleicao;

/**
 * @brief Inicializa uma eleição com valores padrão (zerando as variáveis que armazenam votos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados
 * A memória necessária para os vetores "presidentes", "governadores" deve ser alocada aqui.
 * Demais ponteiros devem ser inicializado com NULL.
 * @return Eleição inicializada.
 */
tEleicao* InicializaEleicao()
{
    tEleicao *eleicao = (tEleicao *) malloc (sizeof(tEleicao));
    eleicao->votosBrancosGovernador = eleicao->votosBrancosPresidente = eleicao->votosNulosGovernador = eleicao->votosNulosPresidente = 0;
    eleicao->totalEleitores = eleicao->totalGovernadores = eleicao->totalPresidentes = 0;
    eleicao->presidentes = (tCandidato **) malloc (sizeof(tCandidato *));
    eleicao->governadores = (tCandidato **) malloc (sizeof(tCandidato *));
    eleicao->eleitores = NULL;

    

    return eleicao;
}


void ApagaEleicao(tEleicao* eleicao)
{
    if(eleicao != NULL)
    {
        for(int i = 0; i < eleicao->totalGovernadores; i++)
        {
            free(eleicao->governadores[i]);
        }
        for(int i = 0; i < eleicao->totalPresidentes; i++)
        {
            free(eleicao->presidentes[i]);
        }
        for(int i = 0; i < eleicao->totalEleitores; i++)
        {
            free(eleicao->eleitores[i]);
        }
        free(eleicao->presidentes);
        free(eleicao->governadores);
        free(eleicao->eleitores);
        free(eleicao);
    }
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada. 
 */
void RealizaEleicao(tEleicao* eleicao)
{
    eleicao->eleitores = (tEleitor **) malloc (sizeof(tEleitor*)*MAX_ELEITORES);
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao* eleicao)
{
    printf("ELEICAO ANULADA\n");
}

