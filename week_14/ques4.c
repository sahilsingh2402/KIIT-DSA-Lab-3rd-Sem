#include <stdio.h>
#include <stdlib.h>
#define hash(x) (x % 10)
typedef struct Node
{
    int data;
    struct Node *link;
} Node;
void initialise(Node *[]);
void insert(Node **, int);
int search(Node *, int);
void delete (Node **, int);
void display(Node *[]);
int main()
{
    Node *arr[10];
    initialise(arr);
    int choice, val;
    do
    {
        printf("1) Insert Data\n2) Search for Data\n");
        printf("3) Display Table\n4) Delete Item\n5) Exit\n->: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            insert(&arr[hash(val)], val);
            break;
        case 2:
            printf("Enter the value to look for: ");
            scanf("%d", &val);
            if (search(arr[hash(val)], val))
                printf("\nItem Found!\n");
            else
                printf("\nItem NOT found!\n");
            break;
        case 3:
            display(arr);
            break;
        case 4:
            printf("Enter the Item to delete: ");
            scanf("%d", &val);
            delete (&arr[hash(val)], val);
            break;
        default:
            printf("Exiting...\n");
        }
        printf("----------------------------------\n");
    } while (choice >= 1 && choice <= 4);
    return 0;
}
void initialise(Node *arr[])
{
    for (int i = 0; i < 10; i++)
        arr[i] = NULL;
}
void insert(Node **start, int val)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = val;
    temp->link = NULL;
    if (!*start)
    {
        *start = temp;
        return;
    }
    Node *tempStart = *start;
    while (tempStart->link)
        tempStart = tempStart->link;
    tempStart->link = temp;
}
int search(Node *start, int val)
{
    while (start)
    {
        if (start->data == val)
            return 1;
        start = start->link;
    }
    return 0;
}
void delete (Node **start, int val)
{
    if (!*start)
    {
        printf("The list is empty!\n");
        return;
    }
    else if ((*start)->data == val)
    {
        Node *ptr = *start;
        *start = (*start)->link;
        free(ptr);
        return;
    }
    Node *tempStart = *start;
    Node *tempPrev = *start;
    while (tempStart && tempStart->data != val)
    {
        tempPrev = tempStart;
        tempStart = tempStart->link;
    }
    if (!tempStart)
    {
        printf("\nItem not found!\n");
        return;
    }
    tempPrev->link = tempStart->link;
    free(tempStart);
}
void display(Node *arr[])
{
    Node *start;
    for (int i = 0; i < 10; i++)
    {
        start = arr[i];
        printf("%d | ", i);
        while (start)
        {
            printf("%d ", start->data);
            start = start->link;
        }
        printf("\n");
    }
}
