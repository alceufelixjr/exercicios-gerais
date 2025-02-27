#include "operacao.h"
#include <stdio.h>
#include <stdlib.h>

struct Operacao
{
    tConta *conta;
    float valorOperacao;
};

/**
 * @brief Cria uma variável (alocada dinamicamente) do tipo tOperacao. Ponteiros devem ser inicializados com NULL e variáveis numéricas com valor zero (exceto aquelas passadas como parâmetro para a função).
 *
 * @param conta - A conta que será associada a uma operação
 * @param valor - O valor da operação
 *
 * @return A variável do tipo tOperacao inicializada.
 */
tOperacao* CriaOperacao(tConta* conta, float valor)
{
    tOperacao *op = (tOperacao *) malloc (sizeof(tOperacao));
    int id = RetornaIdConta(conta);
    op->conta = CriaConta(id);
    op->valorOperacao = valor;

    return op;
}

/**
 * @brief Libera toda a memória alocada para armazenar dados de uma operacao.
 *
 * @param A variável do tipo tOperacao que será apagada.
 */
void DestroiOperacao(tOperacao* op)
{
    DestroiConta(op->conta);
    free(op);
}


/**
 * @brief Consulta o valor de uma operação especifica
 *
 * @param op - A operacao que queremos consultar o valor
 * @return O valor da operação cadastrada
 */
float ConsultaValorOperacao(tOperacao* op)
{
    return(op->valorOperacao);
}


/**
 * @brief Imprime a operação. Ver formato nos exemplos de saída e/ou roteiro.
 *
 * @param op - A operacao que queremos imprimir
 */
void ImprimeOperacao(tOperacao* op)
{
    
    printf("\nOperação na conta %d com valor %.2f\n",RetornaIdConta(op->conta),op->valorOperacao);
}

