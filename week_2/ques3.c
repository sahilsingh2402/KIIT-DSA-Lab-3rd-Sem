// 3. Write a C program to check two matrices are identical or not.
#include <stdio.h>
int main()
{
    int i_535, j_535, rows_535, columns_535, a_535[10][10], b_535[10][10], isEqual_535;

    printf("\nEnter Number of Rows and Columns: ");
    scanf("%d %d", &i_535, &j_535);
    printf("\nEnter the First Matrix Elements:\n");
    for (rows_535 = 0; rows_535 < i_535; rows_535++)
    {
        for (columns_535 = 0; columns_535 < j_535; columns_535++)
        {
            scanf("%d", &a_535[rows_535][columns_535]);
        }
    }

    printf("\nEnter the Second Matrix Elements\n");
    for (rows_535 = 0; rows_535 < i_535; rows_535++)
    {
        for (columns_535 = 0; columns_535 < j_535; columns_535++)
        {
            scanf("%d", &b_535[rows_535][columns_535]);
        }
    }
    isEqual_535 = 1;

    for (rows_535 = 0; rows_535 < i_535; rows_535++)
    {
        for (columns_535 = 0; columns_535 < j_535; columns_535++)
        {
            if (a_535[rows_535][columns_535] != b_535[rows_535][columns_535])
            {
                isEqual_535 = 0;
                break;
            }
        }
    }
    if (isEqual_535 == 1)
    {
        printf("\nMatrix 1 is Equal to Matrix 2");
    }
    else
    {
        printf("\nMatrix 1 is Not Equal to Matrix 2");
    }
    return 0;
}

Enter Number of Rows and Columns: 2 2

Enter the First Matrix Elements:
1 2 
3 4

Enter the Second Matrix Elements
1 2
3 4