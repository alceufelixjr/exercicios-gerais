#include <stdio.h>
#include <stdbool.h>
#include "eleicao.h"


// typedef struct {
//     tCandidato presidentes[MAX_CANDIDATOS_POR_CARGO];
//     int totalPresidentes;

//     tCandidato governadores[MAX_CANDIDATOS_POR_CARGO];
//     int totalGovernadores;

//     int votosBrancosPresidente;
//     int votosNulosPresidente;

//     int votosBrancosGovernador;
//     int votosNulosGovernador;

//     tEleitor eleitores[MAX_ELEITORES];
//     int totalEleitores;
    
// } tEleicao;

/**
 * @brief Inicializa uma eleição com valores padrão (zerando os votos invalidos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados.
 * @return Eleição inicializada.
 */
tEleicao InicializaEleicao()
{
    tEleicao eleicao;
    eleicao.votosBrancosGovernador = eleicao.votosBrancosPresidente = eleicao.votosNulosGovernador = eleicao.votosNulosPresidente = 0;
    
    for(int i = 0; i < MAX_CANDIDATOS_POR_CARGO; i++)
    {
        eleicao.presidentes[i] = CriaCandidato(" "," ",' ', -1);
    }

    for(int i = 0; i < MAX_CANDIDATOS_POR_CARGO; i++)
    {
        eleicao.governadores[i] = CriaCandidato(" "," ",' ',-1);
    }

    int nCandidatos;
    eleicao.totalPresidentes = eleicao.totalGovernadores = 0;
    
    scanf("%d\n",&nCandidatos);
    for(int i = 0; i < nCandidatos; i++)
    {
        tCandidato candidato;
        candidato = LeCandidato();
        char cargo = ObtemCargo(candidato);
        if(cargo == 'P')
        {
            eleicao.presidentes[eleicao.totalPresidentes] = candidato;
            eleicao.totalPresidentes++;
        }else if(cargo == 'G')
        {
            eleicao.governadores[eleicao.totalGovernadores] = candidato;
            eleicao.totalGovernadores++;
        }
    }
    return eleicao;
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 * @return Eleição com os resultados da votação.
 */
tEleicao RealizaEleicao(tEleicao eleicao)
{
    eleicao.totalEleitores = 0;
    
    for(int i = 0; i < MAX_ELEITORES; i++)
    {
        eleicao.eleitores[i] = CriaEleitor(-1,-1,-1);
    }

    int nEleitores;
    scanf("%d\n",&nEleitores);
    for(eleicao.totalEleitores; eleicao.totalEleitores < nEleitores; eleicao.totalEleitores++)
    {
        tEleitor eleitor;
        eleitor = LeEleitor();
        eleicao.eleitores[eleicao.totalEleitores] = eleitor;
        int votoP = ObtemVotoPresidente(eleitor);
        int votoG = ObtemVotoGovernador(eleitor);
        if(votoP == 0)
        {
            eleicao.votosBrancosPresidente++;
        }
        if(votoP != 0)
        {
            for(int i = 0; i <= eleicao.totalPresidentes; i++)
            {
                if(i == eleicao.totalPresidentes)
                {
                    eleicao.votosNulosPresidente++;
                    break;
                }
                else if(VerificaIdCandidato(eleicao.presidentes[i],votoP))
                {
                    eleicao.presidentes[i] = IncrementaVotoCandidato(eleicao.presidentes[i]);
                    break;
                }
            }
        }
        if(votoG == 0)
        {
            eleicao.votosBrancosGovernador++;
        }
        if(votoG != 0)
        {
            for(int i = 0; i <= eleicao.totalGovernadores; i++)
            {
                if(i == eleicao.totalGovernadores)
                {
                    eleicao.votosNulosGovernador++;
                    break;
                }
                else if(VerificaIdCandidato(eleicao.governadores[i],votoG))
                {
                    eleicao.governadores[i] = IncrementaVotoCandidato(eleicao.governadores[i]);
                    break;
                }
            }
        }
    }


    return eleicao;
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao eleicao)
{
    while(1)
    {
        if(eleicao.totalGovernadores > MAX_CANDIDATOS_POR_CARGO || eleicao.totalPresidentes > MAX_CANDIDATOS_POR_CARGO || eleicao.totalEleitores > MAX_ELEITORES)
        {
            printf("ELEICAO ANULADA\n");
            break;
        }
        else
        {
            bool verificaIgualdadeEleitores = false;
            for(int i = 0; i <= eleicao.totalEleitores; i++)
            {
                for(int j = i + 1; j < eleicao.totalEleitores; j++)
                {
                    if(EhMesmoEleitor(eleicao.eleitores[i],eleicao.eleitores[j]))
                    {
                        verificaIgualdadeEleitores = true;      
                    }
                }
            }
            if(verificaIgualdadeEleitores == true)
            {
                printf("ELEICAO ANULADA\n");
                break;
            }
            
            //procurar o vencedor da eleicao de presidente ou governador
            printf("- PRESIDENTE ELEITO: ");
            tCandidato vencedorP;
            vencedorP = eleicao.presidentes[0]; // inicia no primeiro candidato
            for(int i = 0; i < eleicao.totalPresidentes; i++)
            {
                int obtemVotosVencedor = ObtemVotos(vencedorP);
                int obtemVotosCandidato = ObtemVotos(eleicao.presidentes[i]);
                if(obtemVotosVencedor < obtemVotosCandidato)
                {
                    vencedorP = eleicao.presidentes[i];
                }
            }
            if(ObtemVotos(vencedorP) < eleicao.votosBrancosPresidente+eleicao.votosNulosPresidente)
            {
                printf("SEM DECISAO\n");
            }else
            {
                for(int i = 0; i <= eleicao.totalPresidentes; i++)
                {
                    int obtemVotosVencedor = ObtemVotos(vencedorP);
                    int obtemVotosCandidato = ObtemVotos(eleicao.presidentes[i]);
                    if((obtemVotosVencedor == obtemVotosCandidato) && !(EhMesmoCandidato(vencedorP,eleicao.presidentes[i])))
                    {
                        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
                        break;
                    }
                    if(i == eleicao.totalPresidentes)
                    {
                        if(obtemVotosVencedor < eleicao.votosBrancosPresidente+eleicao.votosNulosPresidente)
                        {
                            printf("SEM DECISAO\n");
                        }else
                        {
                            ImprimeCandidato(vencedorP,CalculaPercentualVotos(vencedorP,eleicao.totalEleitores));
                        }
                    }
                }
            }
            
            printf("- GOVERNADOR ELEITO: ");
            tCandidato vencedorG;
            vencedorG = eleicao.governadores[0]; // inicia no primeiro candidato
            for(int i = 0; i < eleicao.totalGovernadores; i++)
            {
                int obtemVotosVencedor = ObtemVotos(vencedorG);
                int obtemVotosCandidato = ObtemVotos(eleicao.governadores[i]);
                if(obtemVotosVencedor < obtemVotosCandidato)
                {
                    vencedorG = eleicao.governadores[i];
                }
            }
        
            {
                for(int i = 0; i <= eleicao.totalGovernadores; i++)
                {
                    int obtemVotosVencedor = ObtemVotos(vencedorG);
                    int obtemVotosCandidato = ObtemVotos(eleicao.governadores[i]);
                    if((obtemVotosVencedor == obtemVotosCandidato) && !(EhMesmoCandidato(vencedorG,eleicao.governadores[i])))
                    {
                        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
                        break;
                    }
                    if(i == eleicao.totalGovernadores)
                    {
                        if(obtemVotosVencedor < eleicao.votosBrancosGovernador+eleicao.votosNulosGovernador)
                        {
                            printf("SEM DECISAO\n");
                        }else
                        {
                            ImprimeCandidato(vencedorG,CalculaPercentualVotos(vencedorG,eleicao.totalEleitores));
                        }
                    }
                }
            }
            printf("- NULOS E BRANCOS: %d, %d\n",eleicao.votosNulosGovernador+eleicao.votosNulosPresidente,eleicao.votosBrancosGovernador+eleicao.votosBrancosPresidente);
            break;
        }
    }
}
