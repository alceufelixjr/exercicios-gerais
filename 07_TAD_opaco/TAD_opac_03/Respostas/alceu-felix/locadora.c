#include "locadora.h"
#include <stdio.h>
#include <stdlib.h>

#define QTD_FILMES 10
#define INCREMENTA_LISTA 5

struct Locadora
{
    tFilme **listaFilmes;
    int lucro;
    int qtdFilmesAlocado;
    int qtdFilmes;
};

/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 * 
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora* CriarLocadora ()
{
    tLocadora *locadora = (tLocadora *) malloc (sizeof(tLocadora));
    if(locadora == NULL)
        exit(1);
    locadora->listaFilmes = (tFilme **) malloc (sizeof(tFilme*));
    if(locadora->listaFilmes == NULL)
        exit(1);
    locadora->qtdFilmes = locadora->lucro = 0;

    return locadora;
}

/**
 * @brief Destrói uma instância de tLocadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora (tLocadora* locadora)
{
    if(locadora != NULL)
    {
        for(int i = 0; i < locadora->qtdFilmes; i++)
        {
            free(locadora->listaFilmes[i]);
        }
        free(locadora->listaFilmes);
        free(locadora);
    }
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser verificada.
 * @param codigo Código do filme a ser verificado.
 * @return int 1 se o filme está cadastrado, 0 caso contrário.
 */
int VerificarFilmeCadastrado (tLocadora* locadora, int codigo)
{
     
    for(int i = 0; i < locadora->qtdFilmes; i++)
    {
        if(EhMesmoCodigoFilme(locadora->listaFilmes[i],codigo))
            return 1;
    }
    return 0;
}

/**
 * @brief Cadastra um novo filme na locadora caso ele não esteja cadastrado.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param filme Ponteiro para o filme a ser cadastrado.
 */
void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme)
{
    int codigoFilmeCadastrado = ObterCodigoFilme(filme);
    if(VerificarFilmeCadastrado(locadora,codigoFilmeCadastrado) == 0)
    {
        if(locadora->qtdFilmesAlocado == locadora->qtdFilmes)
        {
            locadora->qtdFilmesAlocado += INCREMENTA_LISTA;
            locadora->listaFilmes = (tFilme **) realloc (locadora->listaFilmes,sizeof(tFilme *)*locadora->qtdFilmesAlocado);
        }
        locadora->listaFilmes[locadora->qtdFilmes] = filme;
        locadora->qtdFilmes++;
    }
}

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora.
 * 
 * @param Locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerCadastroLocadora (tLocadora* Locadora)
{
    int codigoFilme;
    tFilme * filmeCadastrado = CriarFilme();
    scanf("%d,",&codigoFilme);
    LeFilme(filmeCadastrado,codigoFilme);
    CadastrarFilmeLocadora(Locadora,filmeCadastrado);
}

/**
 * @brief Aluga um ou mais filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Número de códigos de filmes a serem alugados.
 */
void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos);

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora (tLocadora* locadora);

/**
 * @brief Devolve um ou mais filmes alugados da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Número de códigos de filmes a serem devolvidos.
 */
void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos);

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora (tLocadora* locadora);

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora (tLocadora* locadora);

/**
 * @brief Consulta o estoque de filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarEstoqueLocadora (tLocadora* locadora);

/**
 * @brief Consulta o lucro da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora (tLocadora* locadora);
