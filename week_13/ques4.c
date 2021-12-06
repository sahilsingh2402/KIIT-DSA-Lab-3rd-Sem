#include <stdio.h>
#include <time.h>

void merge(int *arr, int left, int mid, int right)
{
    int aux[right];
    int t1 = left, t2 = mid + 1;
    int i = left;
    while (t1 <= mid && t2 <= right)
    {
        if (arr[t1] < arr[t2])
            aux[i++] = arr[t1++];
        else
            aux[i++] = arr[t2++];
    }
    while (t1 <= mid)
        aux[i++] = arr[t1++];
    while (t2 <= right)
        aux[i++] = arr[t2++];
    for (int k = left; k <= right; k++)
        arr[k] = aux[k];
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void merge_sort(int *arr, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
void selection_sort(int *arr, int len)
{
    int k;
    for (int i = 0; i < len - 1; i++)
    {
        k = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[k] > arr[j])
                k = j;
        }
        swap(&arr[k], &arr[i]);
    }
}
void bubble_sort(int *arr, int len)
{
    int largest_index;
    while (len--)
    {
        largest_index = 0;
        for (int j = 1; j <= len; j++)
        {
            if (arr[largest_index] < arr[j])
                largest_index = j;
        }
        swap(&arr[largest_index], &arr[len]);
    }
}
void insertion_sort(int *arr, int len)
{
    int key, j;
    for (int i = 1; i < len; i++)
    {
        key = arr[i];
        j = i;
        while (j > 0 && arr[j - 1] >= key)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}
void quick_sort(int *arr, int left, int right)
{
    if (left >= right)
        return;
    int small_index = left;
    for (int i = left + 1; i <= right; i++)
    {
        if (arr[i] <= arr[left])
        {
            small_index++;
            swap(&arr[i], &arr[small_index]);
        }
    }
    swap(&arr[small_index], &arr[left]);
    quick_sort(arr, left, small_index - 1);
    quick_sort(arr, small_index + 1, right);
}
void display(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    clock_t t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;

    int choice, len;
    int arr[100];
    do
    {
        printf("1) Create a new list\n2) Insertion Sort\n3) Bubble Sort\n");
        printf("4) Selection Sort\n5) merge Sort\n6) Quick Sort\n7) Exit\n->: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            printf("Enter Size: ");
            scanf("%d", &len);
            printf("Enter values: ");
            for (int i = 0; i < len; i++)
                scanf("%d", &arr[i]);
            break;
        case 2:
            t = clock();
            insertion_sort(arr, len);
            t = clock() - t;
            printf("Time taken (in seconds): %f\n", time_taken);
            display(arr, len);
            break;
        case 3:
            t = clock();
            bubble_sort(arr, len);
            t = clock() - t;
            printf("Time taken (in seconds): %f\n", time_taken);
            display(arr, len);
            break;
        case 4:
            t = clock();
            selection_sort(arr, len);
            t = clock() - t;
            printf("Time taken (in seconds): %f\n", time_taken);
            display(arr, len);
            break;
        case 5:
            t = clock();
            merge_sort(arr, 0, len - 1);
            t = clock() - t;
            printf("Time taken (in seconds): %f\n", time_taken);
            display(arr, len);
            break;
        case 6:
            t = clock();
            quick_sort(arr, 0, len - 1);
            t = clock() - t;
            printf("Time taken (in seconds): %f\n", time_taken);
            display(arr, len);
            break;
        default:
            printf("Exiting...\n");
        }
        printf("-------------------------------------------\n");
    } while (choice >= 1 && choice <= 6);
    return 0;
}

