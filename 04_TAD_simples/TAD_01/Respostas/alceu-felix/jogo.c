#include "jogo.h"
#include "tabuleiro.h"
#include <stdio.h>


tJogo CriaJogo()
{
    tJogo jogo;
    tTabuleiro tabuleiro;
    tJogador jogador1;
    tJogador jogador2;
    tabuleiro = CriaTabuleiro();
    jogador1 = CriaJogador(PECA_1);
    jogador2 = CriaJogador(PECA_2);
    jogo.tabuleiro = tabuleiro;
    jogo.jogador1 = jogador1;
    jogo.jogador2 = jogador2;

    return jogo;
}

void ComecaJogo(tJogo jogo)
{
    int jogadorUmOuDois = 1; //alterna entre 1 ou 2 --> se jogadorUmOuDois == 1, joga jogador1, senao joga jogador2
    while(1)
    {
            
        if(jogadorUmOuDois)
        {
            jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
        }
        if(!jogadorUmOuDois)
        {
            jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
        }
        if(AcabouJogo(jogo))
        {
            break;
        }
        jogadorUmOuDois++;
        jogadorUmOuDois = jogadorUmOuDois%2;
    } 
}

int AcabouJogo(tJogo jogo)
{
    if(VenceuJogador(jogo.jogador1,jogo.tabuleiro))
    {
        printf("JOGADOR %d Venceu!\n",PECA_1);
        return 1;
    }
    else if(VenceuJogador(jogo.jogador2,jogo.tabuleiro))
    {
        printf("JOGADOR %d Venceu!\n",PECA_2);
        return 1;
    }
    else if(!TemPosicaoLivreTabuleiro(jogo.tabuleiro))
        return 1;
    return 0;
}

int ContinuaJogo()
{
    char op;
    printf("Jogar novamente? (s,n)\n");
    scanf(" %c",&op);
    if(op == 's')
        return 1;
    else if(op == 'n')
        return 0;
}