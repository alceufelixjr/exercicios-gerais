#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME 10
#define MAX_CPF 10

struct Usuario
{
    char *nome;
    char *cpf;
};

/**
 * @brief Cria um novo usuário.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo usuário criado.
 */
tUsuario *CriaUsuario()
{
    tUsuario * user = (tUsuario *) malloc (sizeof(tUsuario));
    user->nome = (char *) malloc (sizeof(char)*MAX_NOME);
    user->cpf = (char *) malloc (sizeof(char)*MAX_CPF);

    return user;  
}

/**
 * @brief Desaloca a memória de um usuário.
 * 
 * @param user Ponteiro para o usuário a ser destruído.
 */
void DestroiUsuario(tUsuario *user)
{
    if(user != NULL)
    {
        free(user->cpf);
        free(user->nome);
        free(user);
    }
}

/**
 * @brief Lê os dados de um usuário da entrada padrão.
 * 
 * @param user Ponteiro para o usuário a ser lido.
 */
void LeUsuario(tUsuario *user)
{
    scanf(" %s %s",user->nome,user->cpf);
}

/**
 * @brief Imprime os dados de um usuário.
 * 
 * @param user Ponteiro para o usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario *user)
{
    printf("Nome: %s\n",user->nome);
    printf("CPF: %s\n",user->cpf);
}
