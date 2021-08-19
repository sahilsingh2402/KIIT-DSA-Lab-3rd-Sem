// Q1. Write a C Program to merge two sorted array.
#include <stdio.h>
#include <stdlib.h>

int *merge(int A_535[], int B_535[], int size_array_1_535, int size_array_2_535)
{
    int *array_535 = (int *)calloc(size_array_1_535 + size_array_2_535, sizeof(int));
    int i = 0, j = 0, k = 0;

    while (i < size_array_1_535 && j < size_array_2_535)
    {
        if (A_535[i] < B_535[j])
        {
            array_535[k++] = A_535[i++];
            continue;
        }
        else if (A_535[i] > B_535[j])
        {
            array_535[k++] = B_535[j++];
            continue;
        }
        array_535[k++] = A_535[i++];
        array_535[k++] = B_535[j++];
    }
    while (i < size_array_1_535)
    {
        array_535[k++] = A_535[i];
        i++;
    }
    while (j < size_array_2_535)
    {
        array_535[k++] = B_535[j];
        j++;
    }
    return array_535;
}

int main()
{
    int size_array_1_535, size_array_2_535;

    printf("Enter the size of two arrays: ");
    scanf("%d %d", &size_array_1_535, &size_array_2_535);

    int A_535[size_array_1_535], B_535[size_array_2_535];

    printf("Enter in array 1 of size %d: ", size_array_1_535);
    for (int i = 0; i < size_array_1_535; i++)
    {
        scanf("%d", &A_535[i]);
    }

    printf("Enter in array 2 of size %d: ", size_array_2_535);
    for (int j = 0; j < size_array_2_535; j++)
    {
        scanf("%d", &B_535[j]);
    }

    int *array_535 = merge(A_535, B_535, size_array_1_535, size_array_2_535);
    for (int i = 0; i < size_array_1_535 + size_array_2_535; i++)
    {
        printf("%d ", array_535[i]);
    }
    return 0;
}

Enter the size of two arrays: 5 10
Enter in array 1 of size 5: 1 4 6 7 8  
Enter in array 2 of size 10: 1 2 2 3 4 5 8 9 10 14
1 1 2 2 3 4 4 5 6 7 8 8 9 10 14 