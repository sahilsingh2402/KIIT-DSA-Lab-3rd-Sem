#include <stdio.h>
void swap(int *xp, int *yp)
{
    // NAME: Sahil Singh
    // ROLL: 2005535
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n, int size)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
    for (k = 0; k < size; k++)
        printf("%d ", arr[k]);
    printf("\n");
}
int main()
{
    int arr[] = {10, 8, 9, 7, 4, 5, 3, 6, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Sorted array: ");
    bubbleSort(arr, n, n);
    return 0;
}
