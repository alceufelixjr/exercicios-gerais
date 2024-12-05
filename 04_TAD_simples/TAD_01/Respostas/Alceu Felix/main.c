#include "jogo.h"

int main(void)
{
    tJogo jogo;
    jogo = CriaJogo();
    int auxJogo = 1;
    while(auxJogo)
    {
        ComecaJogo(jogo);
        auxJogo = ContinuaJogo();
    }
    return 0;
}