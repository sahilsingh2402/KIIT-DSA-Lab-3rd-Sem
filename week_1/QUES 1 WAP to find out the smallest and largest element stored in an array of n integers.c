#include <stdio.h>
int main()
{
    // NAME: Sahil Singh
    // ROLL: 2005535
    int n, i, small, large;
    printf("Enter the array size: ");
    scanf("%d", &n);

    int array[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    small = array[0];
    large = array[0];
    for (i = 1; i < n; i++)
    {
        if (array[i] < small)
        {
            small = array[i];
        }
        if (array[i] > large)
        {
            large = array[i];
        }
    }

    printf("\nLargest element is: %d", large);
    printf("\nSmallest element is: %d", small);
    return 0;
}
