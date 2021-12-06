#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL;

void create(int arr[], int size)
{
    struct node *temp, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < size; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

int count(struct node *p)
{
    int x = 0;
    while (p)
    {
        x++;
        p = p->next;
    }
    return x;
}

void even_first_493(struct node *start_493)
{
    struct node *prev_493 = NULL;
    struct node *current_493 = start_493;
    while (current_493)
    {
        if (current_493->data % 2 == 0 && prev_493)
        {
            *prev_493->next = *current_493->next;
            current_493->next = start_493;
            start_493 = current_493;
            *current_493 = *prev_493;
        }
        *prev_493 = *current_493;
        *current_493 = *current_493->next;
    }
}
void display(struct node *st)
{
    st = first;
    while (st)
    {
        printf("%d ", st->data);
        st = st->next;
    }
}

int main()
{
    int n;
    printf("enter the size:");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    create(arr, n);
    even_first_493(first);
    display(first);
}