#include <stdio.h>
#include <stdlib.h>

typedef struct Stack_535
{
    int data_535;
    struct Stack_535 *link_535;
} Stack_535;

void push_535(Stack_535 **, int);
int pop_535(Stack_535 **);
int isEmpty_535(Stack_535 *);
void display_535(Stack_535 *);
void enqueue_535(Stack_535 **, int);
int dequeue_535(Stack_535 **);

int main()
{
    typedef Stack_535 Queue_535;
    Queue_535 *queue_535 = NULL;
    int choice_535;
    do
    {
        int val_535;
        printf("1) Insert in Stack\n2) display\n3) Delete top\n4) Exit\n->: ");
        scanf("%d", &choice_535);
        switch (choice_535)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val_535);
            enqueue_535(&queue_535, val_535);
            printf("\ntop->");
            display_535(queue_535);
            break;
        case 2:
            printf("\ntop->");
            display_535(queue_535);
            break;
        case 3:
            printf("\nDeleted element: %d\n", dequeue_535(&queue_535));
            break;
        default:
            printf("\nExiting...\n");
        }
        printf("----------------------------\n");
    } while (choice_535 >= 1 && choice_535 <= 3);
    return 0;
}

void push_535(Stack_535 **Stack_top_535, int num_535)
{
    Stack_535 *temp_535 = (Stack_535 *)malloc(sizeof(Stack_535));
    temp_535->data_535 = num_535;
    temp_535->link_535 = *Stack_top_535;
    *Stack_top_535 = temp_535;
}

int pop_535(Stack_535 **Stack_top_535)
{
    if (isEmpty_535(*Stack_top_535))
    {
        printf("\nUnderflow!");
        return -9999999;
    }
    Stack_535 *temp_535 = (*Stack_top_535);
    *Stack_top_535 = (*Stack_top_535)->link_535;
    int val_535 = temp_535->data_535;
    free(temp_535);
    return val_535;
}

int isEmpty_535(Stack_535 *Stack_top_535)
{
    if (!Stack_top_535)
        return 1;
    return 0;
}

void display_535(Stack_535 *Stack_top_535)
{
    if (isEmpty_535(Stack_top_535))
    {
        printf("\b\b \n");
        return;
    }
    int temp_535 = pop_535(&Stack_top_535);
    printf("%d->", temp_535);
    display_535(Stack_top_535);
    push_535(&Stack_top_535, temp_535);
}

void enqueue_535(Stack_535 **Stack_top_535, int num_535)
{
    if (isEmpty_535(*Stack_top_535))
    {
        push_535(Stack_top_535, num_535);
        return;
    }
    int temp_535 = pop_535(Stack_top_535);
    enqueue_535(Stack_top_535, num_535);
    push_535(Stack_top_535, temp_535);
}

