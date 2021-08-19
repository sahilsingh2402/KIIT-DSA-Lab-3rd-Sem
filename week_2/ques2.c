// 2. Write a C Program to find sum and subtraction of two matrices .
#include <stdio.h>

void readmatrix(int m_535[10][10], int row_535, int col_535)
{
    int i_535, j_535;
    for (i_535 = 0; i_535 < row_535; i_535++)
    {
        for (j_535 = 0; j_535 < col_535; j_535++)
        {
            printf("Enter element [%d,%d] : ", i_535 + 1, j_535 + 1);
            scanf("%d", &m_535[i_535][j_535]);
        }
    }
}

void printmatrix(int m_535[10][10], int row_535, int col_535)
{
    int i_535, j_535;
    for (i_535 = 0; i_535 < row_535; i_535++)
    {
        for (j_535 = 0; j_535 < col_535; j_535++)
        {
            printf("%d ", m_535[i_535][j_535]);
        }
        printf("\n");
    }
}

int main()
{
    int a_535[10][10], b_535[10][10], result_535[10][10];
    int i_535, j_535, rows1_535, cols1_535, rows2_535, cols2_535;

    printf("Number of Rows of Matrix 1: ");
    scanf("%d", &rows1_535);
    printf("Number of Columns of Matrix 1: ");
    scanf("%d", &cols1_535);

    printf("\nEnter Elements of matrix 1:\n");
    readmatrix(a_535, rows1_535, cols1_535);

    printf("Number of Rows of Matrix 2: ");
    scanf("%d", &rows2_535);
    printf("Number of Columns of Matrix 2: ");
    scanf("%d", &cols2_535);

    printf("\nEnter Elements of Matrix 2: \n");
    readmatrix(b_535, rows2_535, cols2_535);

    if (rows1_535 == rows2_535 && cols1_535 == cols2_535)
    {
        for (i_535 = 0; i_535 < rows1_535; i_535++)
        {
            for (j_535 = 0; j_535 < cols1_535; j_535++)
            {
                result_535[i_535][j_535] = a_535[i_535][j_535] + b_535[i_535][j_535];
            }
        }

        printf("\nMatrix after adding:\n");
        printmatrix(result_535, rows1_535, cols1_535);

        for (i_535 = 0; i_535 < rows1_535; i_535++)
        {
            for (j_535 = 0; j_535 < cols1_535; j_535++)
            {
                result_535[i_535][j_535] = a_535[i_535][j_535] - b_535[i_535][j_535];
            }
        }

        printf("\nMatrix after subtracting:\n");
        printmatrix(result_535, rows1_535, cols1_535);
    }
    else
    {
        printf("\nMatrix can not be added, Number of Rows & Columns are Different");
    }
    return 0;
}

Number of Rows of Matrix 1: 2
Number of Columns of Matrix 1: 2

Enter Elements of matrix 1:
Enter element [1,1] : 4
Enter element [1,2] : 4
Enter element [2,1] : 3
Enter element [2,2] : 3
Number of Rows of Matrix 2: 2
Number of Columns of Matrix 2: 2

Enter Elements of Matrix 2: 
Enter element [1,1] : 2
Enter element [1,2] : 2
Enter element [2,1] : 1
Enter element [2,2] : 1

Matrix after adding:
6 6 
4 4 

Matrix after subtracting:
2 2 
2 2 