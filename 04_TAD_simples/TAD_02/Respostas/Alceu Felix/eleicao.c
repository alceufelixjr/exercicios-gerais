#include "eleicao.h"
#include "candidato.h"
#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>

tEleicao InicializaEleicao()
{
    tEleicao eleicao;
    eleicao.totalGovernadores = 0;
    eleicao.totalPresidentes = 0;
    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosPresidente = 0;
    eleicao.votosBrancosGovernador = 0;
    eleicao.votosNulosGovernador = 0;
    int candidatos;
    char cargo;
    scanf("%d\n", &candidatos);
    for (int i = 0;i < candidatos;i++)
    {
        tCandidato candidato;
        candidato = LeCandidato();
        cargo = ObtemCargo(candidato);
        if(cargo == GOVERNADOR && eleicao.totalGovernadores < MAX_CANDIDATOS_POR_CARGO)
        {
            eleicao.governadores[eleicao.totalGovernadores] = candidato;
            eleicao.totalGovernadores++;
        }
        else if(cargo == PRESIDENTE && eleicao.totalPresidentes < MAX_CANDIDATOS_POR_CARGO)
        {
            eleicao.presidentes[eleicao.totalPresidentes] = candidato;
            eleicao.totalPresidentes++;
        }
    }
    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao)
{
    eleicao.totalEleitores = 0;
    int eleitores;
    scanf("%d", &eleitores);
    for (int i = 0; i < eleitores;i++)
    {
        tEleitor eleitor;
        int votoP, votoG;
        int verificaId;
        int count; //SE COUNT == ELEICAO.TOTALPRESIDENTES SIGNIFICA QUE TODOS OS IDS CANDIDATOS SAO DIFERENTES
        eleitor = LeEleitor();
        votoP = ObtemVotoPresidente(eleitor);
        votoG = ObtemVotoGovernador(eleitor);
        if(votoP == 0)
            eleicao.votosBrancosPresidente++;
        if(votoG == 0)
            eleicao.votosBrancosGovernador++;
        count = 0;
        for (int i = 0; i < eleicao.totalPresidentes; i++)
        {
            verificaId = VerificaIdCandidato(eleicao.presidentes[i], votoP);
            if(!verificaId)
                count++;
            if(verificaId)
                IncrementaVotoCandidato(eleicao.presidentes[i]);
        }
        if(count == eleicao.totalPresidentes)
            printf("ITERACAO %d SOMOU\n", i);
            eleicao.votosNulosPresidente++;
        count = 0;
        for (int i = 0; i < eleicao.totalGovernadores; i++)
        {
            verificaId = VerificaIdCandidato(eleicao.governadores[i], votoG);
            if(!verificaId)
                count++;
            if(verificaId)
                IncrementaVotoCandidato(eleicao.governadores[i]);
        }
        if(count == eleicao.totalGovernadores)
            eleicao.votosNulosGovernador++;
        eleicao.eleitores[i] = eleitor;
        eleicao.totalEleitores++;
    }

    return eleicao;
}

void ImprimeResultadoEleicao(tEleicao eleicao)
{
    int votosNulos, votosBrancos;
    for (int i = 0; i < eleicao.totalEleitores; i++)
    {
        for (int j = i + 1; j < eleicao.totalEleitores;j++)
        {
            if(EhMesmoEleitor(eleicao.eleitores[i],eleicao.eleitores[j]))
            {
                printf("ELEICAO ANULADA\n");
                exit(0);
            }                
        }
    }
    printf("- PRESIDENTE ELEITO: ");
        for (int i = 0; i < eleicao.totalPresidentes; i++)
        {
            for (int j = i + 1; j < eleicao.totalPresidentes;j++)
            {
                printf("%d %d\n", eleicao.governadores[i].id,eleicao.governadores[j].id);
                if(EhMesmoCandidato(eleicao.presidentes[i],eleicao.presidentes[j]))
                {
                    printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
                    break;
                }
            }
        }
    printf("- GOVERNADOR ELEITO: ");
  
        for (int i = 0; i < eleicao.totalGovernadores; i++)
        {
            for (int j = i + 1; j < eleicao.totalGovernadores;j++)
            {
                printf("%d %d\n", eleicao.governadores[i].id,eleicao.governadores[j].id);
                if(EhMesmoCandidato(eleicao.governadores[i],eleicao.governadores[j]))
                {
                    printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
                    break;
                }
            }
        }
    votosBrancos = eleicao.votosBrancosGovernador + eleicao.votosBrancosPresidente;
    votosNulos = eleicao.votosNulosGovernador + eleicao.votosNulosPresidente;
    printf("- NULOS E BRANCOS: %d, %d", votosNulos, votosBrancos);
}    
