#include <stdio.h>
#include <stdlib.h>
#define DEFNULL_535 -999999
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
void show_queue_535(Queue_535 *); //debug
int main()
{
    Queue_535 que_535 = {NULL, NULL};
    int choice_535;
    do
    {
        printf("1) Insertion\n2) Display\n3) Deletion\n4) Exit\n->: ");
        scanf("%d", &choice_535);
        int val_535;
        printf("\n");
        switch (choice_535)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val_535);
            enqueue_535(&que_535, val_535);
            show_queue_535(&que_535);
            break;
        case 2:
            show_queue_535(&que_535);
            break;
        case 3:
            printf("Deleted element: ");
            printf("%d\n", dequeue_535(&que_535));
            show_queue_535(&que_535);
            break;
        default:
            printf("Exiting...\n");
        }
        printf("----------------------------------\n");
    } while (choice_535 >= 1 && choice_535 <= 3);
    return 0;
}
void enqueue_535(Queue_535 *que_535, int num_535)
{
    Node_535 *temp_535 = (Node_535 *)malloc(sizeof(Node_535));
    temp_535->data_535 = num_535;
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
void show_queue_535(Queue_535 *que_535)
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

