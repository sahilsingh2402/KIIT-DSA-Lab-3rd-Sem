#include <stdio.h>
#include <stdlib.h>

#define DEFNULL_535 -1

typedef struct Node_535
{
    int data_535;
    struct Node_535 *link_535;
} Node_535;

typedef struct Queue_535
{
    Node_535 *front_535;
    Node_535 *rear_535;
} Queue_535;

void enqueue_535(Queue_535 *, int);
int dequeue_535(Queue_535 *);
int peek_535(Queue_535 *);
int isEmpty_535(Queue_535 *);
void display_535(Queue_535 *);
void push_535(Queue_535 *, int);
int pop_535(Queue_535 *);

int main()
{
    typedef Queue_535 Stack;
    Stack stack = {NULL, NULL};
    int choice, val;
    do
    {
        printf("1) Insert\n2) Delete\n3) Display\n4) Exit\n->: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            push_535(&stack, val);
            display_535(&stack);
            break;
        case 2:
            printf("Deleted element: ");
            printf("%d\n", pop_535(&stack));
            display_535(&stack);
            break;
        case 3:
            display_535(&stack);
            break;
        default:
            printf("Exiting...\n");
        }
        printf("----------------------------\n");
    } while (choice >= 1 && choice <= 3);
    return 0;
}

void enqueue_535(Queue_535 *que_535, int num)
{
    Node_535 *temp_535 = (Node_535 *)malloc(sizeof(Node_535));
    temp_535->data_535 = num;
    temp_535->link_535 = NULL;
    if (isEmpty_535(que_535))
    {
        que_535->front_535 = que_535->rear_535 = temp_535;
        return;
    }
    que_535->rear_535->link_535 = temp_535;
    que_535->rear_535 = que_535->rear_535->link_535;
}

int dequeue_535(Queue_535 *que_535)
{
    if (isEmpty_535(que_535))
        return DEFNULL_535;
    Node_535 *temp_535 = que_535->front_535;
    que_535->front_535 = que_535->front_535->link_535;
    if (que_535->front_535 == NULL)
        que_535->rear_535 = NULL;
    int n = temp_535->data_535;
    free(temp_535);
    return n;
}

int peek_535(Queue_535 *que_535)
{
    if (isEmpty_535(que_535))
        return DEFNULL_535;
    return que_535->front_535->data_535;
}

int isEmpty_535(Queue_535 *que_535)
{
    if (que_535->front_535 == NULL)
        return 1;
    return 0;
}

void display_535(Queue_535 *que_535)
{
    Queue_535 temp_535 = {NULL, NULL};
    while (!isEmpty_535(que_535))
    {
        printf("%d->", peek_535(que_535));
        enqueue_535(&temp_535, dequeue_535(que_535));
    }
    printf("\b\b \n");
    que_535->front_535 = temp_535.front_535;
    que_535->rear_535 = temp_535.rear_535;
}

void push_535(Queue_535 *que_535, int num)
{
    Queue_535 temp_535 = {NULL, NULL};
    while (!isEmpty_535(que_535))
        enqueue_535(&temp_535, dequeue_535(que_535));
    enqueue_535(que_535, num);
    while (!isEmpty_535(&temp_535))
        enqueue_535(que_535, dequeue_535(&temp_535));
}

int pop_535(Queue_535 *que_535)
{
    return dequeue_535(que_535);
}

