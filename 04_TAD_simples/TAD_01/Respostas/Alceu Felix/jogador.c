#include "jogador.h"
#include "jogada.h"
#include "tabuleiro.h"
#include <stdio.h>

tJogador CriaJogador(int idJogador)
{
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    tJogada jogada;
    while(1)
    {
        printf("Jogador %d\n", jogador.id);
        printf("Digite uma posicao (x e y):\n");
        jogada = LeJogada();
        int x = ObtemJogadaX(jogada);
        int y = ObtemJogadaY(jogada);
        if(!jogada.sucesso)
        {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n",x,y);
            continue;
        }
        if(!EstaLivrePosicaoTabuleiro(tabuleiro,x,y))
        {
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
            continue;
        }
        tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, x, y);
        printf("Jogada [%d,%d]!\n", x, y);
        ImprimeTabuleiro(tabuleiro);
        return tabuleiro;
    }
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,0,0,jogador.id))
    {
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,0,1,jogador.id))
        {
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,0,2,jogador.id)) 
                return 1;
        }   
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,1,0,jogador.id))
        {
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,2,0,jogador.id))
                return 1;
        }
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,1,1,jogador.id))
        {
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,2,2,jogador.id))
                return 1;
        }
    }
    else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,2,0,jogador.id))
    {
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,2,1,jogador.id))
        {
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,2,2,jogador.id))
                return 1;
        }
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,1,1,jogador.id))
        {
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,0,2,jogador.id))
                return 1;
        }    
    }
    else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,1,1,jogador.id))
    {
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,0,1,jogador.id))
        {
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,2,1,jogador.id))
                return 1;
        }
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,1,0,jogador.id))
        {
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,1,2,jogador.id))
                return 1;
        }
    }
    else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,0,2,jogador.id))
    {
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,1,2,jogador.id))
        {
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,2,2,jogador.id))
                return 1;
        }
    }
    return 0;
}

