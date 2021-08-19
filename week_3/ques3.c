// Write a program to replace every element in the dynamic array with the next
// greatest element present in the same array.
#include <stdio.h>
int main()
{
    int a[] = {2, 5, 3, 9, 7};
    int len = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i = 0; i < len; i++)
    {
        int max = a[i];
        for (int j = i + 1; j < len; j++)
        {
            if (max < a[j])
            {
                max = a[j];
                break;
            }
        }
        if (max == a[i])
            max = -1;
        a[i] = max;
    }
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
}
