#include <stdio.h>
void nxt_grt_ele(int arr[], int n)
{
    // NAME: Sahil Singh
    // ROLL: 2005535
    int next, i, j;
    for (i = 0; i < n; i++)
    {
        next = -1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                next = arr[j];
                break;
            }
        }
        printf("%d -- %d\n", arr[i], next);
    }
}
int main()
{
    int arr[] = {2, 5, 3, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    nxt_grt_ele(arr, n);
    return 0;
}
