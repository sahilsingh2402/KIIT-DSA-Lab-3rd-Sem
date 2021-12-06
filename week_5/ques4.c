#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int **create_matrix(int, int);
void free_matrix(int **, int);
void convert_to_tuple(int **, int[][3], int, int);
void display_tuple(int[][3]);
void insert(int arr[][3], int row, int a, int b, int c);
void add_tuple(int[][3], int[][3], int[][3]);

int main()
{
    int tupleA[MAX][3], tupleB[MAX][3], tupleC[MAX][3];
    int row, col;
    printf("Enter rows and columns: ");
    scanf("%d%d", &row, &col);
    printf("Enter a sparse matrix (no.1):\n");
    int **arr1 = create_matrix(row, col);
    printf("Enter a sparse matrix (no.2):\n");
    int **arr2 = create_matrix(row, col);
    convert_to_tuple(arr1, tupleA, row, col);
    convert_to_tuple(arr2, tupleB, row, col);
    add_tuple(tupleA, tupleB, tupleC);
    printf("The resultant tuple:\n");
    display_tuple(tupleC);
    free_matrix(arr1, row);
    free_matrix(arr2, row);
    return 0;
}

int **create_matrix(int row, int col)
{
    int **arr = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
        arr[i] = (int *)malloc(col * sizeof(int));
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &arr[i][j]);
    return arr;
}

void free_matrix(int **arr, int row)
{
    for (int i = 0; i < row; i++)
        free(arr[i]);
    free(arr);
}

void convert_to_tuple(int **arr, int tuple[][3], int row, int col)
{
    int count = 0, i, j;
    tuple[0][0] = row;
    tuple[0][1] = col;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (arr[i][j] != 0)
            {
                tuple[++count][0] = i;
                tuple[count][1] = j;
                tuple[count][2] = arr[i][j];
            }
        }
    }
    tuple[0][2] = count;
}

void display_tuple(int arr[][3])
{
    int i, j;
    for (i = 0; i <= arr[0][2]; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

void insert(int arr[][3], int row, int a, int b, int c)
{
    arr[row][0] = a;
    arr[row][1] = b;
    arr[row][2] = c;
}

void add_tuple(int arr1[][3], int arr2[][3], int arr3[][3])
{
    if (arr1[0][0] != arr2[0][0] || arr1[0][1] != arr2[0][1])
    {
        printf("The operattion is not possible!\n");
        return;
    }
    int rowA = 1, rowB = 1;
    int row = 1;
    arr3[0][0] = arr1[0][0];
    arr3[0][1] = arr1[0][1];
    while (rowA <= arr1[0][2] && rowB <= arr2[0][2])
    {
        //if(arr1>arr2) result=arr2: If row is smaller, or row is same but column is smaller
        if (arr1[rowA][0] > arr2[rowB][0] || (arr1[rowA][0] == arr2[rowB][0] &&
                                              arr1[rowA][1] > arr2[rowB][1]))
        {
            insert(arr3, row++, arr2[rowB][0], arr2[rowB][1], arr2[rowB][2]);
            rowB++;
            continue;
        }
        //if(arr2>arr1) result=arr1: If row is smaller, or row is same but column is smaller
        else if (arr1[rowA][0] < arr2[rowB][0] || (arr1[rowA][0] == arr2[rowB][0] &&
                                                   arr1[rowA][1] < arr2[rowB][1]))
        {
            insert(arr3, row++, arr1[rowA][0], arr1[rowA][1], arr1[rowA][2]);
            rowA++;
            continue;
        }
        //if(arr1==arr2) result=arr2+arr1: If row and column both are same
        insert(arr3, row++, arr2[rowB][0], arr2[rowB][1], arr2[rowB][2] + arr1[rowA][2]);
        rowB++;
        rowA++;
    }
    for (; rowA <= arr1[0][2]; rowA++)
        insert(arr3, row++, arr1[rowA][0], arr1[rowA][1], arr1[rowA][2]);
    for (; rowB <= arr2[0][2]; rowB++)
        insert(arr3, row++, arr2[rowB][0], arr2[rowB][1], arr2[rowB][2]);
    arr3[0][2] = row - 1;
}

