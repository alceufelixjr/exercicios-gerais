#include "tabuleiro.h"
#include <stdio.h>


tTabuleiro CriaTabuleiro()
{
    tTabuleiro tabuleiro;
    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';
    tabuleiro.pecaVazio = '-';
    for (int rows = 0; rows < TAM_TABULEIRO; rows++)
    {
        for (int cols = 0; cols < TAM_TABULEIRO; cols++)
        {
            tabuleiro.posicoes[cols][rows] = tabuleiro.pecaVazio;
        }
    }
    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y)
{
    for (int rows = 0; rows < TAM_TABULEIRO; rows++)
    {
        for (int cols = 0; cols < TAM_TABULEIRO; cols++)
        {
            if(rows == x && cols == y)
            {
                if(peca == PECA_1)
                    tabuleiro.posicoes[cols][rows] = tabuleiro.peca1;
                else if(peca == PECA_2)
                    tabuleiro.posicoes[cols][rows] = tabuleiro.peca2;
            }
        }
    }
    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro)
{
    for (int rows = 0; rows < TAM_TABULEIRO; rows++)
    {
        for (int cols = 0; cols < TAM_TABULEIRO; cols++)
        {
            if(tabuleiro.posicoes[cols][rows] == '-')
                return 1;
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca)
{
    for (int rows = 0; rows < TAM_TABULEIRO; rows++)
    {
        for (int cols = 0; cols < TAM_TABULEIRO; cols++)
        {
            if (rows == x && cols == y)
            {
                if(peca == PECA_1)
                {
                    if(tabuleiro.posicoes[cols][rows] == 'X')
                        return 1;
                }
                else if(peca == PECA_2)
                {
                    if(tabuleiro.posicoes[cols][rows] == '0')
                        return 1;
                }
                return 0;
            }          
        }
    }
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y)
{
    for (int rows = 0; rows < TAM_TABULEIRO; rows++)
    {
        for (int cols = 0; cols < TAM_TABULEIRO; cols++)
        {
            if(rows == x && cols == y)
            {
                if(tabuleiro.posicoes[cols][rows] == '-')
                    return 1;
                return 0;
            }
        }
    }
}

int EhPosicaoValidaTabuleiro(int x, int y)
{
    return (x >= 0 && x <= 2 && y >= 0 && y <= 2);
}

void ImprimeTabuleiro(tTabuleiro tabuleiro)
{
    for (int rows = 0; rows < TAM_TABULEIRO; rows++)
    {
        for (int cols = 0; cols < TAM_TABULEIRO; cols++)
        {
            if(cols == 0)
                printf("    %c", tabuleiro.posicoes[rows][cols]);
            else if(cols == 1)
                printf("%c", tabuleiro.posicoes[rows][cols]);
            else if(cols == 2)
                printf("%c\n", tabuleiro.posicoes[rows][cols]);
        }
    }
}