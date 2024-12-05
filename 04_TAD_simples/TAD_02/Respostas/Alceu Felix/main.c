#include "candidato.h"
#include "eleicao.h"
#include "eleitor.h"
#include "constantes.h"
#include <stdio.h>

#define DEBUG 1

int main()
{
    tEleicao eleicao;
    eleicao = InicializaEleicao();
    eleicao = RealizaEleicao(eleicao);
    ImprimeResultadoEleicao(eleicao);
    
    return 0;
}