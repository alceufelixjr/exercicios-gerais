#include <stdio.h>
#include "matrix_utils.h"


void matrix_read(int rows, int cols, int matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}


void matrix_print(int rows, int cols, int matrix[rows][cols])
{
    for (int i = 0; i < rows;i++)
    {
        printf("|");
        for (int j = 0; j < cols;j++)
        {
            printf("%d", matrix[i][j]);
            if(!(j == cols-1))
            {
                printf(" ");    
            }
        }
        printf("|\n");
    }
}

int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2)
{
    if(rows1 == rows2 && cols1 == cols2)
        return 1;
    else
        return 0;
}


int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2)
{
    if(rows1 == rows2 && cols1 == cols2)
        return 1;
    else
        return 0;
}


int possible_matrix_multiply(int cols1, int rows2)
{
    if(cols1 == rows2)
        return 1;
    else
        return 0;
}


void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1])
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1])
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            result[i][j] -= matrix2[i][j];
        }
    }
}


void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2])
{
    
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            for (int a = 0; i < rows2; i++)
            {
                for (int b = 0; j < cols1; j++)
                {
                    result[i][j] += matrix1[a][b] * matrix2[b][a];
                }
            }
        }
    }
}


void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows])
{

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            result[i][j] = matrix[j][i];
        }
    }
}

void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] *= scalar;
        }
    }
}