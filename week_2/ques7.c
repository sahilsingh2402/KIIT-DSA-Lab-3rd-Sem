// 7. Write a C program to find the trace of (sum of diagonal element) matrix.
#include <stdio.h>
int main()
{
    int array_535[10][10];
    int i_535, j_535, m_535, n_535, a_535 = 0, sum_535 = 0;
    printf("Enter the order of the matix \n");
    scanf("%d %d", &m_535, &n_535);
    if (m_535 == n_535)
    {
        printf("Enter the co-efficients of the matrix\n");
        for (i_535 = 0; i_535 < m_535; ++i_535)
        {
            for (j_535 = 0; j_535 < n_535; ++j_535)
            {
                scanf("%d", &array_535[i_535][j_535]);
            }
        }
        printf("The given matrix is \n");
        for (i_535 = 0; i_535 < m_535; ++i_535)
        {
            for (j_535 = 0; j_535 < n_535; ++j_535)
            {
                printf("%d ", array_535[i_535][j_535]);
            }
            printf("\n");
        }
        for (i_535 = 0; i_535 < m_535; ++i_535)
        {
            sum_535 = sum_535 + array_535[i_535][i_535];
            a_535 = a_535 + array_535[i_535][m_535 - i_535 - 1];
        }
        printf("\nThe sum of the main diagonal elements is = %d\n", sum_535);
        printf("The sum of the off diagonal elements is = %d\n", a_535);
    }
    else
        printf("The given order is not square matrix\n");
    return 0;
}

Enter the order of the matix 
2 2
Enter the co-efficients of the matrix
12 14
34 22
The given matrix is 
12 14
34 22

The sum of the main diagonal elements is = 34
The sum of the off diagonal elements is = 48