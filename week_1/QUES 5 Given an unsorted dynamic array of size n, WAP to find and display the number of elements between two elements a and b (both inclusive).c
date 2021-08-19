#include <stdio.h>
int main()
{
    // NAME: Sahil Singh
    // ROLL: 2005535
    int arr[10] = {1, 2, 2, 7, 5, 4}, a, b, ctr = 0, count = 0;

    printf("Array: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nEnter a and b: ");
    scanf("%d %d", &a, &b);

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == a)
        {
            count = 1;
        }
        if (arr[i] == b)
        {
            break;
        }
        if (count = 1)
        {
            ctr++;
        }
    }

    printf("\nOutput: %d", ctr);
    return 0;
}
