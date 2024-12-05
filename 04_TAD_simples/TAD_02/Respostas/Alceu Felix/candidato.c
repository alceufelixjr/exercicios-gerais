#include "candidato.h"
#include "constantes.h"
#include <string.h>
#include <stdio.h>

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id)
{
    tCandidato candidato;
    strcpy(candidato.nome, nome);
    strcpy(candidato.partido, partido);
    candidato.cargo = cargo;
    candidato.id = id;
    candidato.votos = 0;
    return candidato;
}

tCandidato LeCandidato()
{
    tCandidato candidato;
    scanf("%[^,], %[^,], %c, %d", candidato.nome, candidato.partido, &candidato.cargo, &candidato.id);
    candidato.votos = 0;
    return candidato;
}

int VerificaIdCandidato(tCandidato candidato, int id)
{
    if(candidato.id == id)
        return 1;
    return 0;
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2)
{
    if(candidato1.votos == candidato2.votos)
        return 1;
    else if(candidato1.id == candidato2.id)
        return 1;
    return 0;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato)
{
    candidato.votos++;
    return candidato;
}

int ObtemVotos(tCandidato candidato)
{
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos)
{
    return (candidato.votos / (float)totalVotos)*CONVERT_PERCENTAGE;
}

char ObtemCargo(tCandidato candidato)
{
    return candidato.cargo;
}

void ImprimeCandidato(tCandidato candidato, float percentualVotos)
{
    printf("%s (%s), %d votos, %.2f%%",candidato.nome,candidato.partido,candidato.votos,percentualVotos);
}

