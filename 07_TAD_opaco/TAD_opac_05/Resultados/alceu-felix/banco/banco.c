#include "banco.h"
#include "conta.h"
#include <stdio.h>
#include <stdlib.h>

#define QTD_CONTAS 5
#define INCREMENTA_QTD_CONTAS 2

struct Banco
{
    tConta **contas;
    int qtdContasAloc;
    int qtdContas;
};

/**
 * @brief Cria um novo banco, com 5 contas alocadas e nenhuma conta aberta.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo banco criado.
 */
tBanco *CriaBanco()
{
    tBanco * banco = (tBanco *) malloc (sizeof(tBanco));
    banco->qtdContasAloc = QTD_CONTAS;
    banco->contas = (tConta **) malloc (sizeof(tConta *)*banco->qtdContasAloc);
    banco->qtdContas = 0;

    return banco;
}

/**
 * @brief Desaloca a memória de um banco e de todas as suas contas.
 * 
 * @param banco Ponteiro para o banco a ser destruído.
 */
void DestroiBanco(tBanco *banco)
{
    if(banco != NULL)
    {
        for(int i = 0; i < banco->qtdContas; i++)
        {
            DestroiConta(banco->contas[i]);
        }
        free(banco->contas);
        free(banco);
    }
    
}

/**
 * @brief Abre uma nova conta no banco e a adiciona ao vetor de contas.
 * 
 * @param banco Ponteiro para o banco onde a conta será aberta.
 */
void AbreContaBanco(tBanco *banco)
{
    tConta *conta = CriaConta();
    LeConta(conta);
    
    if(banco->qtdContas == banco->qtdContasAloc)
    {
        banco->qtdContasAloc += INCREMENTA_QTD_CONTAS;
        banco->contas = (tConta **) realloc (banco->contas,sizeof(tConta *)*banco->qtdContasAloc);
    }
    banco->contas[banco->qtdContas] = conta;
    banco->qtdContas++;
}

/**
 * @brief Realiza um saque em uma conta do banco se ela existir e tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta e o valor do saque.
 * 
 * @param banco Ponteiro para o banco onde a conta será sacada.
 */
void SaqueContaBanco(tBanco *banco)
{
    int numConta;
    float valorSacado;
    numConta = valorSacado = 0;
    scanf("%d %f\n",&numConta, &valorSacado);
    
    for(int i = 0; i < banco->qtdContas; i++)
    {
        if(VerificaConta(banco->contas[i],numConta))
            SaqueConta(banco->contas[i],valorSacado);
    }
}

/**
 * @brief Realiza um depósito em uma conta do banco se ela existir.
 * Nessa função é necessário ler o número da conta e o valor do depósito. 
 * 
 * @param banco Ponteiro para o banco onde a conta será depositada.
 */
void DepositoContaBanco(tBanco *banco)
{
    int numConta;
    float valorDepositado;
    numConta = valorDepositado = 0;
    scanf("%d %f\n",&numConta, &valorDepositado);
    
    for(int i = 0; i < banco->qtdContas; i++)
    {
        if(VerificaConta(banco->contas[i],numConta))
            DepositoConta(banco->contas[i],valorDepositado);
    }
}

/**
 * @brief Realiza uma transferência entre duas contas do banco se elas existirem e a conta de origem tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta de origem, o número da conta de destino e o valor da transferência.
 * 
 * @param banco Ponteiro para o banco onde as contas estão.
 */
void TransferenciaContaBanco(tBanco *banco)
{
    int numContaDestino, numContaOrigem;
    float valorDepositado;
    numContaDestino = valorDepositado = numContaOrigem = 0;
    scanf("%d %d %f\n",&numContaDestino, &numContaOrigem ,&valorDepositado);
    
    for(int i = 0; i < banco->qtdContas; i++)
    {
        if(VerificaConta(banco->contas[i],numContaDestino))
        {
            for(int j = 0; j < banco->qtdContas; j++)
            {
                if(VerificaConta(banco->contas[j],numContaOrigem))
                    TransferenciaConta(banco->contas[i],banco->contas[j],valorDepositado);
            }
        }
    }
}

/**
 * @brief Imprime o relatório do banco, com todas as contas e seus respectivos dados.
 * 
 * @param banco Ponteiro para o banco a ser impresso.
 */
void ImprimeRelatorioBanco(tBanco *banco)
{
    printf("===| Imprimindo Relatorio |===\n");
    for(int i = 0; i < banco->qtdContas; i++)
    {
        ImprimeConta(banco->contas[i]);
    }
}

