#include "jogada.h"
#include "tabuleiro.h"
#include <stdio.h>

tJogada LeJogada()
{
    tJogada jogada;
    scanf("%d %d", &jogada.x, &jogada.y);
    jogada.sucesso = EhPosicaoValidaTabuleiro(jogada.x, jogada.y);
    return jogada;
}

int ObtemJogadaX(tJogada jogada)
{
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada)
{
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada)
{
    return jogada.sucesso;
}