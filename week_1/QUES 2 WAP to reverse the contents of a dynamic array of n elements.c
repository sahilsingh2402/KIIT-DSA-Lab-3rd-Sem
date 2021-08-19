#include <stdio.h>
void reverse(int array[], int start, int end, int size)
{
    // NAME: Sahil Singh
    // ROLL: 2005535
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
