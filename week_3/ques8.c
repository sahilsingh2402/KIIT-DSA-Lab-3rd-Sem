#include <stdio.h>
#include <stdlib.h>
void row_interchange_535(int **, int, int);
int **create_2d_array_535(int, int);
void input0_output1_535(int **, int, int, int);
int main()
{
    int row_535, col_535;
    printf("Enter Rows and columns: ");
    scanf("%d%d", &row_535, &col_535);
    int **arr_535 = create_2d_array_535(row_535, col_535);
    printf("Enter values in matrix:\n");
    input0_output1_535(arr_535, row_535, col_535, 0);
    row_interchange_535(arr_535, row_535, col_535);
    printf("\nOutput:\n");
    input0_output1_535(arr_535, row_535, col_535, 1);
    free(arr_535);
    return 0;
}
void row_interchange_535(int **arr_535, int row_535, int col_535)
{
    for (int j = 0, k = col_535 - 1; j < col_535 / 2; j++, k--)
        for (int i = 0; i < row_535; i++)
        {
            int temp = arr_535[i][j];
            arr_535[i][j] = arr_535[i][k];
            arr_535[i][k] = temp;
        }
}
int **create_2d_array_535(int row_535, int col_535)
{
    int **arr_535 = (int **)malloc(row_535 * sizeof(int *));
    for (int i = 0; i < row_535; i++)
        arr_535[i] = (int *)malloc(col_535 * sizeof(int));
    return arr_535;
}
void input0_output1_535(int **arr_535, int row_535, int col_535, int mode)
{
    for (int i = 0; i < row_535; i++)
    {
        for (int j = 0; j < col_535; j++)
        {
            if (!mode)
            {
                scanf("%d", &arr_535[i][j]);
                continue;
            }
            printf("%d ", arr_535[i][j]);
        }
        if (mode)
            printf("\n");
    }
}

