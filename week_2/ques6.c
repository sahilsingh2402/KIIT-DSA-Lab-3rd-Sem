// 6. Write a C program to find the frequency of even numbers in matrix.
#include <stdio.h>
int main()
{
    int array_535[10][10];
    int i_535, j_535, m_535, n_535, even_535 = 0, odd_535 = 0;

    printf("Enter the number of rows and columns of the matrix: \n");
    scanf("%d %d", &m_535, &n_535);

    printf("Enter the elements of matrix: \n");
    for (i_535 = 0; i_535 < m_535; ++i_535)
    {
        for (j_535 = 0; j_535 < n_535; ++j_535)
        {
            scanf("%d", &array_535[i_535][j_535]);
            if ((array_535[i_535][j_535] % 2) == 0)
            {
                ++even_535;
            }
            else
                ++odd_535;
        }
    }
    printf("The given matrix is: \n");
    for (i_535 = 0; i_535 < m_535; ++i_535)
    {
        for (j_535 = 0; j_535 < n_535; ++j_535)
        {
            printf("%d ", array_535[i_535][j_535]);
        }
        printf("\n");
    }
    printf("\nThe frequency of occurrence of odd number = %d\n", odd_535);
    printf("The frequency of occurrence of even number = %d\n", even_535);

    return 0;
}

Enter the number of rows and columns of the matrix: 
3 3
Enter the elements of matrix: 
1 3 1 
2 1 1
2 3 1
The given matrix is: 
1 3 1 
2 1 1 
2 3 1 

The frequency of occurrence of odd number = 7
The frequency of occurrence of even number = 2