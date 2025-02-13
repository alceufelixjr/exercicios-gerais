#include "conta.h"
#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>

struct Conta
{
    tUsuario *usuario;
    int numConta;
    float saldoConta;
};

/**
 * @brief Cria uma nova conta.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para a nova conta criada.
 */
tConta *CriaConta()
{
    tConta *conta = (tConta *) malloc (sizeof(tConta));
    conta->usuario = CriaUsuario();
    conta->numConta = -1;
    conta->saldoConta = -1;
    return conta;
}

/**
 * @brief Desaloca a memória de uma conta.
 * 
 * @param conta Ponteiro para a conta a ser destruída.
 */
void DestroiConta(tConta *conta)
{
    if(conta != NULL)
    {
        DestroiUsuario(conta->usuario);
        free(conta);
    }
}

/**
 * @brief Lê os dados de uma conta e do usuario atraves da entrada padrão.
 * 
 * @param conta Ponteiro para a conta a ser lida.
 */
void LeConta(tConta *conta)
{
    LeUsuario(conta->usuario);
    scanf(" %d\n",&conta->numConta);
    conta->saldoConta = 0;
}

/**
 * @brief Imprime os dados de uma conta e do proprietário.
 * 
 * @param conta Ponteiro para a conta a ser impressa.
 */
void ImprimeConta(tConta *conta)
{
    printf("Conta: %d\n",conta->numConta);
    printf("Saldo: R$ %.2f\n",conta->saldoConta);
    ImprimeUsuario(conta->usuario);
}

/**
 * @brief Verifica se uma conta possui o numero especificado.
 * 
 * @param conta Ponteiro para a conta a ser verificada.
 * @param numero Número da conta a ser verificado.
 * @return 1 se a conta possui o número especificado, 0 caso contrário.
 */
int VerificaConta(tConta *conta, int numero)
{
    return(conta->numConta == numero);
}

/**
 * @brief Realiza um saque em uma conta caso o saldo seja suficiente.
 * 
 * @param conta Ponteiro para a conta a ser sacada.
 * @param valor Valor a ser sacado.
 */
void SaqueConta(tConta *conta, float valor)
{
    if(conta->saldoConta >= valor)
    {
        conta->saldoConta -= valor;
    }
}

/**
 * @brief Realiza um depósito em uma conta.
 * 
 * @param conta Ponteiro para a conta a ser depositada.
 * @param valor Valor a ser depositado.
 */
void DepositoConta(tConta *conta, float valor)
{
    conta->saldoConta += valor;
}

/**
 * @brief Realiza uma transferência entre duas contas, caso o saldo da conta de origem seja suficiente.
 * 
 * @param destino Ponteiro para a conta de destino.
 * @param origem Ponteiro para a conta de origem.
 * @param valor Valor a ser transferido.
*/
void TransferenciaConta(tConta *destino, tConta *origem, float valor)
{
    if(origem->saldoConta > valor)
    {
        DepositoConta(destino,valor);
        SaqueConta(origem,valor);
    }
}

