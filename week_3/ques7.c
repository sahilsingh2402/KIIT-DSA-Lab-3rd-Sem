#include <stdio.h>
#include <stdlib.h>
void segg_0s_and_1s_535(int[], int);
int main()
{
    int size_535;
    printf("Enter size of array: ");
    scanf("%d", &size_535);
    int *arr_535 = (int *)malloc(size_535 * sizeof(int));
    for (int i = 0; i < size_535; i++)
        scanf("%d", &arr_535[i]);
    segg_0s_and_1s_535(arr_535, size_535);
    for (int i = 0; i < size_535; i++)
        printf("%d ", arr_535[i]);
    printf("\n");
    free(arr_535);
    return 0;
}
void segg_0s_and_1s_535(int arr_535[], int size_535)
{
    int i = 0, j = size_535 - 1;
    while (i < j)
    {
        if (arr_535[i] == 1 && arr_535[j] == 0)
        {
            arr_535[i++] = 0;
            arr_535[j--] = 1;
        }
        if (arr_535[j] == 1)
            j--;
        if (arr_535[i] == 0)
            i++;
    }
}