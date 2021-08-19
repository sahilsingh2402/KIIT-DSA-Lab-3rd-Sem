// WAP to sort rows of a dynamic matrix having m rows and n columns in
// ascending and columns in descending order.
#include <stdio.h>
#include <stdlib.h>
void sort_row_asc_535(int **, int, int);
void sort_column_desc_535(int **, int, int);
int **create_2d_array_535(int, int);
int main()
{
    int row_535, col_535;
    printf("Enter dimensions of matrix: ");
    scanf("%d%d", &row_535, &col_535);
    int **arr_535 = create_2d_array_535(row_535, col_535);
    printf("Enter value in matrix:\n");
    for (int i = 0; i < row_535; i++)
        for (int j = 0; j < col_535; j++)
            scanf("%d", &arr_535[i][j]);
    sort_row_asc_535(arr_535, row_535, col_535);
    sort_column_desc_535(arr_535, row_535, col_535);
    printf("\nOutput:\n");
    for (int i = 0; i < row_535; i++)
    {
        for (int j = 0; j < col_535; j++)
            printf("%d ", arr_535[i][j]);
        printf("\n");
    }
    free(arr_535);
    return 0;
}
void sort_row_asc_535(int **A_535, int row_535, int col_535)
{
    for (int i = 0; i < row_535; i++)
    {
        for (int j = 0; j < col_535 - 1; j++)
            for (int k = 0; k < col_535 - j - 1; k++)
            {
                if (A_535[i][k + 1] < A_535[i][k])
                {
                    int temp_535 = A_535[i][k + 1];
                    A_535[i][k + 1] = A_535[i][k];
                    A_535[i][k] = temp_535;
                }
            }
    }
}
void sort_column_desc_535(int **A_535, int row_535, int col_535)
{
    for (int i = 0; i < col_535; i++)
    {
        for (int j = 0; j < row_535 - 1; j++)
            for (int k = 0; k < row_535 - j - 1; k++)
            {
                if (A_535[k + 1][i] > A_535[k][i])
                {
                    int temp_535 = A_535[k + 1][i];
                    A_535[k + 1][i] = A_535[k][i];
                    A_535[k][i] = temp_535;
                }
            }
    }
}
int **create_2d_array_535(int row_535, int col_535)
{
    int **arr_535 = (int **)malloc(row_535 * sizeof(int *));
    for (int i = 0; i < row_535; i++)
        arr_535[i] = (int *)malloc(col_535 * sizeof(int));
    return arr_535;
}

