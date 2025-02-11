#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>

// typedef struct{
//     char** posicoes;
//     char peca1;
//     char peca2;
//     char pecaVazio;
// } tTabuleiro;

/**
 * Aloca e retorna uma estrutura do tipo tTabuleiro.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tTabuleiro alocada.
 */
tTabuleiro* CriaTabuleiro()
{
    tTabuleiro *tabuleiro = (tTabuleiro *) malloc (sizeof(tTabuleiro));
    if(tabuleiro == NULL)
        exit(1);
    tabuleiro->posicoes = (char **) calloc (TAM_TABULEIRO,sizeof(char *));
    if(tabuleiro->posicoes == NULL)
        exit(1);
    for(int i = 0; i < TAM_TABULEIRO; i++)
    {
        tabuleiro->posicoes[i] = (char *) calloc (TAM_TABULEIRO,sizeof(char));
        if(tabuleiro->posicoes[i] == NULL)
            exit(1);
    }

    tabuleiro->peca1 = 'X';
    tabuleiro->peca2 = 'O';
    tabuleiro->pecaVazio = '-';
    for(int i = 0; i < TAM_TABULEIRO; i++)
    {
        for(int j = 0; j < TAM_TABULEIRO; j++)
        {
            tabuleiro->posicoes[i][j] = tabuleiro->pecaVazio;
        }
    }
    

    return tabuleiro;
}


/**
 * Libera a memória de uma estrutura do tipo tTabuleiro.
 * 
 * @param tabuleiro a estrutura do tipo tTabuleiro a ser liberada.
 */
void DestroiTabuleiro(tTabuleiro* tabuleiro)
{
    if(tabuleiro != NULL){
        for(int i = 0; i < TAM_TABULEIRO; i++)
        {
            free(tabuleiro->posicoes[i]);
        }
        free(tabuleiro->posicoes);
        free(tabuleiro);
    }
}


/**
 * Marca uma posição do tabuleiro com a peça do jogador.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 */
void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y)
{
    if((x >= 0 && x < TAM_TABULEIRO) && (y >= 0 && y < TAM_TABULEIRO))
    {
        if(peca == PECA_1)
            tabuleiro->posicoes[x][y] = tabuleiro->peca1;
        else if(peca == PECA_2)
            tabuleiro->posicoes[x][y] = tabuleiro->peca2;
    }
}


/**
 * Verifica se há alguma posição livre no tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se há alguma posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro)
{
    for(int  i = 0; i < TAM_TABULEIRO; i++)
    {
        for(int j = 0; j < TAM_TABULEIRO; j++)
        {
            if(tabuleiro->posicoes[i][j] == tabuleiro->pecaVazio)
                return 1;
        }
    }
    return 0;
}


/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 * 
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * @param peca a peça do jogador (1 ou 2).
 * 
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca)
{
    if((x >= 0 && x < TAM_TABULEIRO) && (y >= 0 && y < TAM_TABULEIRO))
    {
        if(tabuleiro->posicoes[x][y] == 'X' && peca == PECA_1)
            return 1;
        else if(tabuleiro->posicoes[x][y] == 'O' && peca == PECA_2)
            return 1;
    }
    return 0;
}


/**
 * Verifica se a posição do tabuleiro está livre.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * 
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y)
{
    if((x >= 0 && x < TAM_TABULEIRO) && (y >= 0 && y < TAM_TABULEIRO))
    {
        if(tabuleiro->posicoes[x][y] == tabuleiro->pecaVazio)
            return 1;
    }
    return 0;
}


/**
 * Verifica se a posição do tabuleiro é válida.
 * 
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * 
 * @return 1 se a posição é válida, 0 caso contrário.
 */
int EhPosicaoValidaTabuleiro(int x, int y)
{
    return ((x >= 0 && x < TAM_TABULEIRO) && (y >= 0 && y < TAM_TABULEIRO));
}


/**
 * Imprime o tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro* tabuleiro)
{
    for(int i = 0; i < TAM_TABULEIRO; i++)
    {
        for(int j = 0; j < TAM_TABULEIRO; j++)
        {
                printf("%c",tabuleiro->posicoes[i][j]);
        }
        printf("\n");
    }
}


