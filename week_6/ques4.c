/*Write a program to represent a sparse matrix in three tuple format using linked list and write addition
function to perform addition.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node_535
{
    int row_535;
    int col_535;
    int data_535;
    struct Node_535 *link_535;
} Node_535;
void insert_535(Node_535 **, int, int, int);
int **create_2d_array_535(int, int);
Node_535 *matrix_to_tuple_535(int **, int, int);
void print_tuple_535(Node_535 *);
Node_535 *add_tuple_535(Node_535 *, Node_535 *);
int main()
{
    int row_535, col_535;
    printf("Enter number of rows and columns for the matrix: ");
    scanf("%d%d", &row_535, &col_535);
    printf("Enter elements, sparse matrix 1:\n");
    int **arr1_535 = create_2d_array_535(row_535, col_535);
    printf("\nEnter elements, sparse matrix 2:\n");
    int **arr2_535 = create_2d_array_535(row_535, col_535);
    Node_535 *tuple1_535 = matrix_to_tuple_535(arr1_535, row_535, col_535);
    Node_535 *tuple2_535 = matrix_to_tuple_535(arr2_535, row_535, col_535);
    printf("\nTuple 1:\n");
    print_tuple_535(tuple1_535);
    printf("\nTuple 2:\n");
    print_tuple_535(tuple2_535);
    Node_535 *tuple3_535 = add_tuple_535(tuple1_535, tuple2_535);
    printf("\nResultant tuple_535:\n");
    print_tuple_535(tuple3_535);
    return 0;
}
void insert_535(Node_535 **tuple_535, int row_535, int col_535, int data_535)
{
    Node_535 *temp_535 = (Node_535 *)malloc(sizeof(Node_535));
    temp_535->row_535 = row_535;
    temp_535->col_535 = col_535;
    temp_535->data_535 = data_535;
    temp_535->link_535 = NULL;
    if (!*tuple_535)
    {
        *tuple_535 = temp_535;
        return;
    }
    Node_535 *dummyHead_535 = *tuple_535;
    while (dummyHead_535->link_535)
    {
        dummyHead_535 = dummyHead_535->link_535;
    }
    (*tuple_535)->data_535++;
    dummyHead_535->link_535 = temp_535;
}
int **create_2d_array_535(int row_535, int col_535)
{
    int **arr_535 = (int **)malloc(row_535 * sizeof(int *));
    for (int i = 0; i < row_535; i++)
        arr_535[i] = (int *)malloc(col_535 * sizeof(int));
    for (int i = 0; i < row_535; i++)
        for (int j = 0; j < col_535; j++)
            scanf("%d", &arr_535[i][j]);
    return arr_535;
}
Node_535 *matrix_to_tuple_535(int **arr_535, int row_535, int col_535)
{
    Node_535 *tuple_535 = (Node_535 *)malloc(sizeof(Node_535));
    tuple_535->row_535 = row_535;
    tuple_535->col_535 = col_535;
    tuple_535->data_535 = 0;
    tuple_535->link_535 = NULL;
    Node_535 *head_535 = tuple_535;
    for (int i = 0; i < row_535; i++)
    {
        for (int j = 0; j < col_535; j++)
            if (arr_535[i][j] < 0 || arr_535[i][j] > 0)
            {
                Node_535 *temp_535 = (Node_535 *)malloc(sizeof(Node_535));
                temp_535->row_535 = i;
                temp_535->col_535 = j;
                temp_535->data_535 = arr_535[i][j];
                temp_535->link_535 = NULL;
                tuple_535->link_535 = temp_535;
                tuple_535 = temp_535;
                head_535->data_535++;
            }
    }
    return head_535;
}
void print_tuple_535(Node_535 *tuple_535)
{
    while (tuple_535)
    {
        printf("%d %d %d\n", tuple_535->row_535, tuple_535->col_535, tuple_535->data_535);
        tuple_535 = tuple_535->link_535;
    }
}
Node_535 *add_tuple_535(Node_535 *tuple1_535, Node_535 *tuple2_535)
{
    Node_535 *tuple3_535 = NULL;
    insert_535(&tuple3_535, tuple1_535->row_535, tuple1_535->col_535, 0);
    tuple1_535 = tuple1_535->link_535;
    tuple2_535 = tuple2_535->link_535;
    while (tuple1_535 && tuple2_535)
    {
        if (tuple1_535->row_535 > tuple2_535->row_535)
        {
            insert_535(&tuple3_535, tuple2_535->row_535, tuple2_535->col_535,
                       tuple2_535->data_535);
            tuple2_535 = tuple2_535->link_535;
            continue;
        } //that or this
        else if (tuple1_535->row_535 == tuple2_535->row_535)
        {
            if (tuple1_535->col_535 > tuple2_535->col_535)
            {
                insert_535(&tuple3_535, tuple2_535->row_535, tuple2_535->col_535,
                           tuple2_535->data_535);
                tuple2_535 = tuple2_535->link_535;
                continue;
            }
        } //Repetation of code to reduce text wrapping in pdf
        else if (tuple1_535->row_535 < tuple2_535->row_535)
        {
            insert_535(&tuple3_535, tuple1_535->row_535, tuple1_535->col_535,
                       tuple1_535->data_535);
            tuple1_535 = tuple1_535->link_535;
            continue;
        } //that or this
        else if (tuple1_535->row_535 == tuple2_535->row_535)
        {
            if (tuple1_535->col_535 < tuple2_535->col_535)
            {
                insert_535(&tuple3_535, tuple1_535->row_535, tuple1_535->col_535,
                           tuple1_535->data_535);
                tuple1_535 = tuple1_535->link_535;
                continue;
            }
        }
        insert_535(&tuple3_535, tuple2_535->row_535, tuple2_535->col_535,
                   tuple2_535->data_535 + tuple1_535->data_535);
        tuple1_535 = tuple1_535->link_535;
        tuple2_535 = tuple2_535->link_535;
    }
    while (tuple1_535)
    {
        insert_535(&tuple3_535, tuple1_535->row_535, tuple1_535->col_535,
                   tuple1_535->data_535);
        tuple1_535 = tuple1_535->link_535;
    }
    while (tuple2_535)
    {
        insert_535(&tuple3_535, tuple2_535->row_535, tuple2_535->col_535,
                   tuple2_535->data_535);
        tuple2_535 = tuple2_535->link_535;
    }
    return tuple3_535;
}

