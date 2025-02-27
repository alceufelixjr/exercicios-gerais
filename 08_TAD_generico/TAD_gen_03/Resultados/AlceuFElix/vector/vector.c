#include "vector.h"
#include <stdlib.h>

struct Vector
{
    data_type **dadosVetor;
    int numElemVetor;
    int numElemVetorAloc;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct()
{
    Vector *v = (Vector *) malloc (sizeof(Vector));
    v->numElemVetor = 0;
    v->numElemVetorAloc = 5;
    v->dadosVetor = (void **) malloc (sizeof(void *)*v->numElemVetorAloc);

    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, data_type val)
{
    if(v->numElemVetor == v->numElemVetorAloc)
    {
        v->numElemVetorAloc *= 2;
        v->dadosVetor = (void **) realloc (v->dadosVetor,sizeof(void*) * v->numElemVetorAloc);
    }
    v->dadosVetor[v->numElemVetor++] = val;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return data_type Elemento do vetor
*/
data_type VectorGet(Vector *v, int i)
{
    return(v->dadosVetor[i]);
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v)
{
    return(v->numElemVetor);
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(data_type))
{
    for(int i = 0; i < v->numElemVetor; i++)
    {
        destroy(v->dadosVetor[i]);
    }
    free(v->dadosVetor);
    free(v);
}


