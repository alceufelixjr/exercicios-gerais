#include "utils.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * Função que cria uma matriz de inteiros, alocada dinamicamente. Se a alocação falhar, o programa é encerrado.
 * 
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz. 
 * @return Ponteiro para a matriz alocada.
*/
int **CriaMatriz(int linhas, int colunas)
{
    int **matriz = (int **) malloc (linhas*sizeof(int *));
    if(matriz == NULL)
    {
        printf("ERROR!\n");
        return 0;
    }
    for(int i = 0; i < linhas; i++)
        matriz[i] = (int *) malloc (colunas*sizeof(int)); 
    return matriz;
}
/**
 * Função que libera a memória alocada para uma matriz de inteiros.
 * 
 * @param matriz Ponteiro para a matriz a ser liberada.
 * @param linhas Número de linhas da matriz.
*/
void LiberaMatriz(int **matriz, int linhas)
{
    for(int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

/**
 * Função que lê uma matriz de inteiros da entrada padrão.
 * 
 * @param matriz Ponteiro para a matriz a ser lida.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
*/
void LeMatriz(int **matriz, int linhas, int colunas)
{
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            scanf("%d",&matriz[i][j]);
        }
    }
}

/**
 * Imprime a matriz transposta da matriz dada.
 * 
 * @param matriz Ponteiro para a matriz.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
*/
void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas)
{
    int **matrizTemp = CriaMatriz(colunas,linhas);

    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            matrizTemp[i][j] = matriz[j][i]; 
        }
    }

    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            if(j == colunas-1)
                printf("%d\n",matrizTemp[i][j]);
            else
                printf("%d ",matrizTemp[i][j]);
        }
    }

    LiberaMatriz(matrizTemp,colunas);
}


