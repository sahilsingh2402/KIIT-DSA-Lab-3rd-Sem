// 5. Write a C program to arrange column elements in ascending order.
#include <stdio.h>
int main()
{
    int ma_535[10][10], mb_535[10][10];
    int i_535, j_535, k_535, a_535, m_535, n_535;
    printf("Enter the number of rows and columns of the matrix: \n");
    scanf("%d %d", &m_535, &n_535);

    printf("Enter the elements of the matrix: \n");
    for (i_535 = 0; i_535 < m_535; ++i_535)
    {
        for (j_535 = 0; j_535 < n_535; ++j_535)
        {
            scanf("%d", &ma_535[i_535][j_535]);
            mb_535[i_535][j_535] = ma_535[i_535][j_535];
        }
    }
    printf("The given matrix is \n");
    for (i_535 = 0; i_535 < m_535; ++i_535)
    {
        for (j_535 = 0; j_535 < n_535; ++j_535)
        {
            printf("%d ", ma_535[i_535][j_535]);
        }
        printf("\n");
    }
    printf("After arranging the columns in ascending order \n");
    for (j_535 = 0; j_535 < n_535; ++j_535)
    {
        for (i_535 = 0; i_535 < m_535; ++i_535)
        {
            for (k_535 = i_535 + 1; k_535 < m_535; ++k_535)
            {
                if (ma_535[i_535][j_535] > mb_535[k_535][j_535])
                {
                    a_535 = mb_535[i_535][j_535];
                    mb_535[i_535][j_535] = mb_535[k_535][j_535];
                    mb_535[k_535][j_535] = a_535;
                }
            }
        }
    }
    for (i_535 = 0; i_535 < m_535; ++i_535)
    {
        for (j_535 = 0; j_535 < n_535; ++j_535)
        {
            printf("%d ", mb_535[i_535][j_535]);
        }
        printf("\n");
    }
    return 0;
}

Enter the number of rows and columns of the matrix: 
2 2
Enter the elements of the matrix: 
12 15
10 11
The given matrix is 
12 15 
10 11 
After arranging the columns in ascending order 
10 11 
12 15 