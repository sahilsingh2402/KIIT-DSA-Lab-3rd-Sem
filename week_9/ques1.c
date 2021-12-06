#include <stdio.h>
#include <stdlib.h>
#define DEFNULL_535 -99999
#define MAXSIZE_535 100
typedef struct Queue_535
{
    int front_535;
    int rear_535;
    int data_535[MAXSIZE_535];
} Queue_535;
void enqueue_535(Queue_535 *, int);
int dequeue_535(Queue_535 *);
int peek_535(Queue_535 *);
int isFull_535(Queue_535 *);
int isEmpty_535(Queue_535 *);
void cpy_535(Queue_535 *, Queue_535 *);
void reverse_535(Queue_535 *);
void show_queue_535(Queue_535 *); //debug
void util_cpy_535(Queue_535 *, Queue_535 *);
int main()
{
    Queue_535 q1_535 = {-1, -1};
    Queue_535 q2_535 = {-1, -1};
    int choice_535;
    do
    {
        printf("1) Insertion\n2) Display\n3) Deletion\n");
        printf("4) Copy\n5) Reverse\n6) Exit\n->: ");
        scanf("%d", &choice_535);
        int val_535;
        printf("\n");
        switch (choice_535)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val_535);
            enqueue_535(&q1_535, val_535);
            show_queue_535(&q1_535);
            break;
        case 2:
            show_queue_535(&q1_535);
            break;
        case 3:
            printf("Deleted element: ");
            printf("%d\n", dequeue_535(&q1_535));
            show_queue_535(&q1_535);
            break;
        case 4:
            printf("Copied Queue:\n");
            cpy_535(&q1_535, &q2_535);
            show_queue_535(&q2_535);
            break;
        case 5:
            printf("Reversed Queue:\n");
            reverse_535(&q1_535);
            show_queue_535(&q1_535);
            break;
        default:
            printf("Exiting...\n");
        }
        printf("----------------------------------\n");
    } while (choice_535 >= 1 && choice_535 <= 5);
    return 0;
}
void enqueue_535(Queue_535 *que_535, int num_535)
{
    if (isFull_535(que_535))
    {
        printf("Overflow!\n");
        return;
    }
    else if (isEmpty_535(que_535))
        que_535->front_535 = que_535->rear_535 = 0;
    else
        que_535->rear_535 = (que_535->rear_535 + 1) % MAXSIZE_535;
    que_535->data_535[que_535->rear_535] = num_535;
}
int dequeue_535(Queue_535 *que_535)
{
    int retIndex_535 = que_535->front_535;
    if (isEmpty_535(que_535))
    {
        printf("Underflow!\n");
        return DEFNULL_535;
    }
    else if (que_535->front_535 == que_535->rear_535)
    {
        que_535->front_535 = que_535->rear_535 = -1;
        return que_535->data_535[retIndex_535];
    }
    que_535->front_535 = (que_535->front_535 + 1) % MAXSIZE_535;
    return que_535->data_535[retIndex_535];
}
int peek_535(Queue_535 *que_535)
{
    if (isEmpty_535(que_535))
        return DEFNULL_535;
    return que_535->data_535[que_535->front_535];
}
int isFull_535(Queue_535 *que_535)
{
    if ((que_535->rear_535 + 1) % MAXSIZE_535 == que_535->front_535)
        return 1;
    return 0;
}
int isEmpty_535(Queue_535 *que_535)
{
    if (que_535->front_535 == -1)
        return 1;
    return 0;
}
void cpy_535(Queue_535 *que1_535, Queue_535 *que2_535)
{
    que2_535->front_535 = que2_535->rear_535 = -1;
    util_cpy_535(que1_535, que2_535);
    reverse_535(que1_535);
}
void reverse_535(Queue_535 *que_535)
{
    if (isEmpty_535(que_535))
        return;

    int temp_535 = dequeue_535(que_535);
    reverse_535(que_535);
    enqueue_535(que_535, temp_535);
}
void show_queue_535(Queue_535 *que_535)
{
    Queue_535 tempQue_535 = {-1, -1};
    while (!isEmpty_535(que_535))
    {
        enqueue_535(&tempQue_535, peek_535(que_535));
        printf("%d->", dequeue_535(que_535));
    }
    while (!isEmpty_535(&tempQue_535))
        enqueue_535(que_535, dequeue_535(&tempQue_535));
    printf("\b\b \n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void util_cpy_535(Queue_535 *que1_535, Queue_535 *que2_535)
{
    if (isEmpty_535(que1_535))
        return;
    int temp_535 = dequeue_535(que1_535);
    enqueue_535(que2_535, temp_535);
    util_cpy_535(que1_535, que2_535);
    enqueue_535(que1_535, temp_535);
}
