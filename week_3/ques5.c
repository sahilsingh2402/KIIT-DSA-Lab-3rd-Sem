#include <stdio.h>
#include <stdlib.h>
void bubble_sort_535(int[], int);
void kth_large_and_small_535(int[], int, int);
int main()
{
    int size_535, k;
    printf("Enter size of array: ");
    scanf("%d", &size_535);
    int *arr_535 = (int *)malloc(size_535 * sizeof(int));
    for (int i = 0; i < size_535; i++)
        scanf("%d", &arr_535[i]);
    printf("Enter value of k: ");
    scanf("%d", &k);
    kth_large_and_small_535(arr_535, size_535, k);
    free(arr_535);
    return 0;
}
void bubble_sort_535(int arr_535[], int size_535)
{
    for (int i = 0; i < size_535 - 1; i++)
        for (int j = 0; j < size_535 - 1 - i; j++)
        {
            if (arr_535[j + 1] < arr_535[j])
            {
                int temp = arr_535[j + 1];
                arr_535[j + 1] = arr_535[j];
                arr_535[j] = temp;
            }
        }
}
void kth_large_and_small_535(int arr_535[], int size_535, int k)
{
    bubble_sort_535(arr_535, size_535);
    if (k < 1 || k > size_535)
    {
        printf("Error: K out of bounds!\n");
        return;
    }
    printf("%dth Largest: %d\n", k, arr_535[size_535 - k]);
    printf("%dth Smallest: %d\n", k, arr_535[k - 1]);
}

