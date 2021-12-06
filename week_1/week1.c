/*
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


#include <stdio.h>
void reverse(int array[], int start, int end, int size)
{
    int temp;
    while (start < end)
    {
        temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(array) / sizeof(array[0]);
    printf("Reversed array: ");
    reverse(array, 0, n - 1, n);
    return 0;
}

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


#include <stdio.h>
void swap(int *xp, int *yp)
{
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
*/

#include <stdio.h>
int main()
{
    // NAME: Sahil Singh
    // ROLL: 2005535
    int i, j, r1, c1, c = 0, p = 1, s = 0;
    printf("Enter number of rows: ");
    scanf("%d", &r1);

    printf("Enter number of columns: ");
    scanf("%d", &c1);

    int a[r1][c1];
    printf("Enter Matrix:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] > 0 || a[i][j] < 0)
                c = c + 1;
        }
    }
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            if (i == j)
                p = p * a[i][j];
        }
    }
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            if (j > i)
                s = s + a[i][j];
        }
    }
    printf("\nMatrix Formed:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            printf("%d ", a[i][j]);
            if (j == c1 - 1)
                printf("\n");
        }
    }
    printf("\nNumber of Non Zero Elements: %d\n", c);
    printf("Sum of Elements above Leading Diagonal: %d\n", s);

    printf("Elements Below Leading Diagonal: ");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            if (j < i)
                printf("%d ", a[i][j]);
        }
    }
    printf("\nProduct of Diagonal: %d\n", p);
    return 0;
}
