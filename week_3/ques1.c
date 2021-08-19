// Given an unsorted dynamic array arr and two numbers x and y, find the
// minimum distance between x and y in arr. The array might also contain
// duplicates. You may assume that both x and y are different and present in arr.
#include <stdio.h>
#include <stdlib.h>
#define INFINITE_535 1000000
int between_535(int[], int, int, int);
int main()
{
    unsigned int size_535;
    printf("Enter size of array: ");
    scanf("%d", &size_535);

    int *arr_535 = (int *)malloc(size_535 * sizeof(int));
    printf("Enter elements in array: ");
    for (int i = 0; i < size_535; i++)
        scanf("%d", &arr_535[i]);

    int x, y;
    printf("Enter two elements: ");
    scanf("%d%d", &x, &y);

    printf("The minimum distance between the two elements: ");
    printf("%d\n", between_535(arr_535, size_535, x, y));
    free(arr_535);
    return 0;
}
int between_535(int arr_535[], int size_535, int x, int y)
{
    int distance_535 = INFINITE_535;
    int i = 0, j = 1;
    while (i < size_535)
    {
        if (arr_535[i] == x)
        {
            while (arr_535[j] != y && j < size_535)
            {
                if (arr_535[j] == x)
                    i = j;
                j++;
            }
            if (arr_535[j] == y && j < size_535)
                distance_535 = (j - i < distance_535) ? j - i : distance_535;
            i = j;
            continue;
        }
        else if (arr_535[i] == y)
        {
            while (arr_535[j] != x && j < size_535)
            {
                if (arr_535[j] == y)
                    i = j;
                j++;
            }
            if (arr_535[j] == x && j < size_535)
                distance_535 = (j - i < distance_535) ? j - i : distance_535;
            i = j;
            continue;
        }
        i++;
    }
    return distance_535;
}
