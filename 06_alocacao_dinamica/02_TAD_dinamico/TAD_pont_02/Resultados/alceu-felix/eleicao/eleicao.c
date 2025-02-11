#include "eleicao.h"
#include <stdio.h>
#include <stdlib.h>

// #define MAX_CANDIDATOS_POR_CARGO 3
// #define MAX_ELEITORES 10

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
    
    tEleicao *eleicao = (tEleicao *) calloc (1,sizeof(tEleicao));
    eleicao->presidentes = (tCandidato **) malloc (sizeof(tCandidato *));
    eleicao->governadores = (tCandidato **) malloc (sizeof(tCandidato *));
    eleicao->eleitores = NULL;
    eleicao->votosBrancosGovernador = eleicao->votosNulosGovernador = eleicao->votosBrancosPresidente =  eleicao->votosNulosPresidente = 0;
    eleicao->totalPresidentes = eleicao->totalGovernadores = eleicao->totalEleitores = 0;
    
    int qtdCandidatos;
    scanf("%d\n",&qtdCandidatos);
    for(int i = 0 ;i < qtdCandidatos; i++)
    {
        tCandidato *candidato = CriaCandidato();
        LeCandidato(candidato);

        if(ObtemCargo(candidato) == 'P')
        {
            eleicao->presidentes[eleicao->totalPresidentes] = candidato;
            eleicao->totalPresidentes++;
        }
        else if(ObtemCargo(candidato) == 'G')
        {
            eleicao->governadores[eleicao->totalGovernadores] = candidato;
            eleicao->totalGovernadores++;
        }
        ApagaCandidato(candidato);
    }

    return eleicao;
}


void ApagaEleicao(tEleicao* eleicao)
{
    if(eleicao != NULL)
    {
        for(int i = 0; i < eleicao->totalEleitores; i++)
        {
            ApagaEleitor(eleicao->eleitores[i]);
        }
        for(int i = 0; i < eleicao->totalGovernadores; i++)
        {
            ApagaCandidato(eleicao->governadores[i]);
        }
        for(int i = 0; i < eleicao->totalPresidentes; i++)
        {
            ApagaCandidato(eleicao->presidentes[i]);
        }
        free(eleicao->eleitores);
        free(eleicao->governadores);
        free(eleicao->presidentes);
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
    int qtdEleitores;
    scanf("%d\n",&qtdEleitores);
    for(int  i = 0; i < qtdEleitores; i++)
    {
        LeEleitor(eleicao->eleitores[eleicao->totalEleitores]);
        for(int  i = 0; i < eleicao->totalPresidentes; i++)
        {
            if(!ObtemVotoPresidente(eleicao->eleitores[eleicao->totalEleitores]))
            {
                eleicao->votosBrancosPresidente++;
                break;
            }
            else if(VerificaIdCandidato(eleicao->presidentes[i],ObtemVotoPresidente(eleicao->eleitores[eleicao->totalEleitores])))
                IncrementaVotoCandidato(eleicao->presidentes[i]);
            else if(i == eleicao->totalPresidentes - 1)
                eleicao->votosNulosPresidente++;
        }
        for(int  i = 0; i < eleicao->totalGovernadores; i++)
        {
            if(!ObtemVotoGovernador(eleicao->eleitores[eleicao->totalEleitores]))
            {
                eleicao->votosBrancosGovernador++;
                break;
            }
            else if(VerificaIdCandidato(eleicao->governadores[i],ObtemVotoGovernador(eleicao->eleitores[eleicao->totalEleitores])))
                IncrementaVotoCandidato(eleicao->governadores[i]);
            else if(i == eleicao->totalGovernadores - 1)
                eleicao->votosNulosGovernador++;
        }
        eleicao->totalEleitores++;
    }
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao *eleicao)
{
    printf("ELEICAO ANULADA\n");
}

