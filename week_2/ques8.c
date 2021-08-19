// 8. Write a C program to multiply two matrix.
#include <stdio.h>
int main()
{
    int m_535, n_535, p_535, q_535, c_535, d_535, k_535, sum_535 = 0;
    int first_535[10][10], second_535[10][10], multiply_535[10][10];

    printf("Enter number of rows and columns of first matrix\n");
    scanf("%d%d", &m_535, &n_535);

    printf("Enter elements of first matrix\n");
    for (c_535 = 0; c_535 < m_535; c_535++)
        for (d_535 = 0; d_535 < n_535; d_535++)
            scanf("%d", &first_535[c_535][d_535]);
    printf("Enter number of rows and columns of second matrix\n");
    scanf("%d%d", &p_535, &q_535);
    if (n_535 != p_535)
        printf("The multiplication isn't possible.\n");
    else
    {
        printf("Enter elements of second matrix\n");
        for (c_535 = 0; c_535 < p_535; c_535++)
            for (d_535 = 0; d_535 < q_535; d_535++)
                scanf("%d", &second_535[c_535][d_535]);
        for (c_535 = 0; c_535 < m_535; c_535++)
        {
            for (d_535 = 0; d_535 < q_535; d_535++)
            {
                for (k_535 = 0; k_535 < p_535; k_535++)
                {
                    sum_535 = sum_535 + first_535[c_535][k_535] * second_535[k_535][d_535];
                }
                multiply_535[c_535][d_535] = sum_535;
                sum_535 = 0;
            }
        }
        printf("Product of the matrices:\n");
        for (c_535 = 0; c_535 < m_535; c_535++)
        {
            for (d_535 = 0; d_535 < q_535; d_535++)
                printf("%d ", multiply_535[c_535][d_535]);
            printf("\n");
        }
    }
    return 0;
}

Enter number of rows and columns of first matrix
2 2
Enter elements of first matrix
1 2
2 1
Enter number of rows and columns of second matrix
2 2
Enter elements of second matrix
1 2 
2 1
Product of the matrices:
5 4
4 5