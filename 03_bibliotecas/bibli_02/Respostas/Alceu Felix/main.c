#include <stdio.h>
#include "matrix_utils.h"

int main()
{
    int op; 
    int rows1, cols1, rows2, cols2;
    int scalar;

    scanf("%d %d",&rows1,&cols1);
    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);

    scanf("%d %d", &rows2, &cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows2, cols2, matrix2);


    while(1)
    {
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida: ");
        scanf("%d", &op);
        if(op == 1)
        {
            if(possible_matrix_sum(rows1,cols1,rows2,cols2))
            {
                matrix_add(rows1,cols1,matrix1,rows2,cols2,matrix2,matrix1);
                matrix_print(rows1,cols1,matrix1);
                printf("\n");
                continue;
            }    
            else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
                printf("\n");
                continue;
            }
        }
        if(op == 2)
        {
            if(possible_matrix_sub(rows1,cols1,rows2,cols2))
            {
                matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2,matrix1);
                matrix_print(rows1,cols1,matrix1);
                printf("\n");
                continue;
            }else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
                printf("\n");
                continue;
            }
        }
        if(op == 3)
        {
            if(possible_matrix_multiply(cols1,rows2))
            {
                matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, matrix1);
                matrix_print(rows1,cols2,matrix1);
                printf("\n");
                continue;
            }else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
                printf("\n");
                continue;
            }
        }
        if(op == 4)
        {
            scanf("%d", &scalar);
            scalar_multiply(rows1,cols1,matrix1,scalar);
            matrix_print(rows1, cols1, matrix1);
            printf("\n");
            continue;
        }
        if(op == 5)
        {
            transpose_matrix(rows1,cols1,matrix1,matrix1);
            transpose_matrix(rows2,cols2,matrix2,matrix2);
            matrix_print(rows1, cols1, matrix1);
            matrix_print(rows2, cols2, matrix2);
            printf("\n");
            continue;
        }
        if(op == 6)
            break;
    }

    return 0;
}