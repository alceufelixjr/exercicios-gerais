#include "aluno.h"
#include <stdlib.h>

#define MAX_TAM_NOME 20

struct Aluno
{
    char *nome;
    int nota;
    char genero;
};

/**
 * @brief Aloca memoria para um aluno
 * 
 * @return A estrutura tAluno inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
tAluno *CriaAluno()
{
    tAluno *aluno = (tAluno *) malloc (sizeof(tAluno));
    aluno->nome = (char *) malloc (sizeof(char)*MAX_TAM_NOME);
    return aluno;
}

/**
 * @brief Libera a memoria alocada para um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * Dica: Foi usado data_type para generalizar a funcao e usar na estrutura Vector. Por isso, é necessário fazer um cast para tAluno* dentro da função.
*/
void DestroiAluno(data_type aluno)
{
    tAluno* aluno_ptr = (tAluno *) aluno;
    free(aluno_ptr->nome);
    free(aluno_ptr);
}

/**
 * @brief Le os dados de um aluno
 * 
 * @param aluno Ponteiro para o aluno
*/
void LeAluno(tAluno *aluno);

/**
 * @brief Retorna o genero de um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * @return char Genero do aluno
*/
char GetGeneroAluno(tAluno *aluno);

/**
 * @brief Retorna a nota de um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * @return float Nota do aluno
*/
float GetNotaAluno(tAluno *aluno);



