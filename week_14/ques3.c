#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define hash(x) (x % 10)
int calc_index(int *, int);
int search_index(int *, int);
int delete (int *, int);
int main()
{
    int *hashTable = (int *)calloc(MAX, sizeof(int));
    int choice, val, index;
    do
    {
        printf("1) Insert Data\n2) Search for Data\n3) Display Table\n");
        printf("4) Delete Item\n5) Exit\n->: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            index = calc_index(hashTable, val);
            if (index == -1)
            {
                printf("\nThe hash table is full!\n");
                break;
            }
            else if (index == -2)
            {
                printf("\nYou cannot enter duplicate values!\n");
                break;
            }
            hashTable[index] = val;
            break;
        case 2:
            printf("Enter the value to look for: ");
            scanf("%d", &val);
            index = search_index(hashTable, val);
            if (index == -1)
            {
                printf("\nItem NOT found!\n");
                break;
            }
            printf("\nItem FOUND at index %d!\n", index);
            break;
        case 3:
            for (int i = 0; i < MAX; i++)
                printf("%d ", hashTable[i]);
            printf("\n");
            break;
        case 4:
            printf("Enter the item to delete: ");
            scanf("%d", &val);
            if (delete (hashTable, val))
                printf("\nItem deleted!\n");
            else
                printf("\nItem NOT found!\n");
            break;
        default:
            printf("Exiting...\n");
        }
        printf("----------------------------------\n");
    } while (choice >= 1 && choice <= 4);
    free(hashTable);
    return 0;
}
int calc_index(int *hashTable, int val)
{
    int offset = 0;
    int valueAt = hashTable[(hash(val) + offset) % MAX];
    while ((valueAt != 0 && valueAt != -1) && offset < MAX)
    {
        if (valueAt == val)
            return -2;
        offset++;
        valueAt = hashTable[(hash(val) + offset) % MAX];
    }
    if (offset >= MAX)
        return -1;
    return (hash(val) + offset) % MAX;
}
int search_index(int *hashTable, int val)
{
    int offset = 0;
    int valueAt = hashTable[(hash(val) + offset) % MAX];
    while (valueAt != 0 && offset < MAX)
    {
        if (valueAt == val)
            return (hash(val) + offset) % MAX;
        offset++;
        valueAt = hashTable[(hash(val) + offset) % MAX];
    }
    return -1;
}
int delete (int *hashTable, int val)
{
    int offset = 0;
    int valueAt = hashTable[(hash(val) + offset) % MAX];
    while (offset < MAX && valueAt != 0)
    {
        if (valueAt == val)
        {
            hashTable[(hash(val) + offset) % MAX] = -1;
            return 1;
        }
        offset++;
        valueAt = hashTable[(hash(val) + offset) % MAX];
    }
    return 0;
}

