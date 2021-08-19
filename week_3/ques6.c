#include <stdio.h>
#include <stdlib.h>
void largest_num_and_count_535(int[], int);
int main()
{
    int size_535;
    printf("Enter size of array: ");
    scanf("%d", &size_535);
    int *arr_535 = (int *)malloc(size_535 * sizeof(int));
    printf("Enter values in array: ");
    for (int i = 0; i < size_535; i++)
        scanf("%d", &arr_535[i]);
    largest_num_and_count_535(arr_535, size_535);
    free(arr_535);
    return 0;
}
void largest_num_and_count_535(int arr_535[], int size_535)
{
    int largest = arr_535[0];
    int count = 1;
    for (int i = 1; i < size_535; i++)
    {
        if (largest < arr_535[i])
        {
            largest = arr_535[i];
            count = 1;
        }
        else if (largest == arr_535[i])
            count++;
    }
    printf("\nLargest Value: %d\n", largest);
    printf("Times present: %d\n", count);
}
