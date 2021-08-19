// 4. Write a C program to arrange row elements in ascending order.
#include <stdio.h>
void main()
{
    int matrix_a_535[10][10], matrix_b_535[10][10];
    int i_535, j_535, k_535, a_535, m_535, n_535;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &m_535, &n_535);

    printf("Enter the elements of the matrix: \n");
    for (i_535 = 0; i_535 < m_535; ++i_535)
    {
        for (j_535 = 0; j_535 < n_535; ++j_535)
        {
            scanf("%d", &matrix_a_535[i_535][j_535]);
            matrix_b_535[i_535][j_535] = matrix_a_535[i_535][j_535];
        }
    }
    printf("The given matrix is \n");
    for (i_535 = 0; i_535 < m_535; ++i_535)
    {
        for (j_535 = 0; j_535 < n_535; ++j_535)
        {
            printf("%d ", matrix_a_535[i_535][j_535]);
        }
        printf("\n");
    }
    printf("After arranging rows in ascending order\n");
    for (i_535 = 0; i_535 < m_535; ++i_535)
    {
        for (j_535 = 0; j_535 < n_535; ++j_535)
        {
            for (k_535 = (j_535 + 1); k_535 < n_535; ++k_535)
            {
                if (matrix_a_535[i_535][j_535] > matrix_a_535[i_535][k_535])
                {
                    a_535 = matrix_a_535[i_535][j_535];
                    matrix_a_535[i_535][j_535] = matrix_a_535[i_535][k_535];
                    matrix_a_535[i_535][k_535] = a_535;
                }
            }
        }
    }
    for (i_535 = 0; i_535 < m_535; ++i_535)
    {
        for (j_535 = 0; j_535 < n_535; ++j_535)
        {
            printf("%d ", matrix_a_535[i_535][j_535]);
        }
        printf("\n");
    }
}

Enter the number of rows and columns of the matrix: 2 2
Enter the elements of the matrix: 
17 7 
4 18
The given matrix is 
17 7 
4 18 
After arranging rows in ascending order
7 17 
4 18 