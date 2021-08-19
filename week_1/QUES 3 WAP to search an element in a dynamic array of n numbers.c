#include <stdio.h>
int main()
{
    // NAME: Sahil Singh
    // ROLL: 2005535
    int i, n, key;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements in array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            printf("Element found at index %d\n", i);
            return 0;
        }
    }
    printf("Element not found!!!\n");
    return 0;
}
