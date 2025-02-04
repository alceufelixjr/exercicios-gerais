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
    tTabuleiro* tabuleiro = (tTabuleiro*) malloc (sizeof(tTabuleiro));
    if(tabuleiro == NULL)
    {
        printf("ERRO!\n");
        exit(1);
    }
    tabuleiro->posicoes = (char**) malloc (TAM_TABULEIRO*sizeof(char*));
    if(tabuleiro->posicoes == NULL)
    {
        printf("ERRO!\n");
        exit(1);
    }
    for(int i = 0;i < TAM_TABULEIRO; i++)
    {
        tabuleiro->posicoes[i] = (char *) malloc (sizeof(char));
        if(tabuleiro->posicoes[i] == NULL)
        {
            printf("ERRO!\n");
            exit(1);
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
    for(int i = 0; i < TAM_TABULEIRO; i++)
    {
        free(tabuleiro->posicoes[i]);
    }
    free(tabuleiro->posicoes);
    free(tabuleiro);
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
    for(int i = 0; i < TAM_TABULEIRO; i++)
    {
        if(i == x)
        {
            for(int  j = 0; j < TAM_TABULEIRO; j++)
            {
                if(j == y)
                {
                    if(peca == PECA_1)
                    {
                        tabuleiro->posicoes[i][j] = 'X';
                    }
                    else if(peca == PECA_2)
                        tabuleiro->posicoes[i][j] = 'O';
                }
            }
        }
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
    for(int i = 0; i < TAM_TABULEIRO; i++)
    {
        for(int j = 0; j < TAM_TABULEIRO; j++)
        {
            if(tabuleiro->posicoes[i][j] == '-')
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
    for(int i = 0; i < TAM_TABULEIRO; i++)
    {
        if(i == x)
        {
            for(int  j = 0; j < TAM_TABULEIRO; j++)
            {
                if(j == y)
                {
                    if(peca == 1)
                        if(tabuleiro->posicoes[i][j] == 'X')
                            return 1;
                    else if(peca == 2)
                        if(tabuleiro->posicoes[i][j] == 'O')
                            return 1;
                }
            }
        }
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
    for(int i = 0; i < TAM_TABULEIRO; i++)
    {
        if(i == x)
        {
            for(int  j = 0; j < TAM_TABULEIRO; j++)
            {
                if(j == y)
                {
                    if(tabuleiro->posicoes[i][j] == '-')
                        return 1;
                }
            }
        }
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
    return(x < TAM_TABULEIRO && y < TAM_TABULEIRO);
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
            if(j == TAM_TABULEIRO-1)
            {
                printf("%d\n",tabuleiro->posicoes[i][j]);
            }
            else
            {
                printf("%d ",tabuleiro->posicoes[i][j]);
            }
        }
    }    
}
