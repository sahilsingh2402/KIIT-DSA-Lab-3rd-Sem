// WAP to arrange the elements of a dynamic array such that all even numbers are followed by all odd numbers.
#include <stdio.h>
#include <stdlib.h>
void odd_to_even(int arr[], int size)
{
    for (int i = 1, j = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0 && arr[j] % 2 == 1)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
        else if (arr[j] % 2 == 0)
            j++;
    }
}
int main()
{
    unsigned int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    printf("Enter elements in array: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    odd_to_even(arr, size);

    printf("Your arranged array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}
