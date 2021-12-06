#include <stdio.h>
#include <stdlib.h>

#define DEFNULL_535 -1
#define MAXSIZE_535 100

typedef struct Queue_535
{
    int front_535;
    int rear_535;
    int data_535[MAXSIZE_535];
} Queue_535;

void enqueue_535(Queue_535 *, int);
int dequeue_535(Queue_535 *);
int isFull_535(Queue_535 *);
int isEmpty_535(Queue_535 *);
void show_queue_535(Queue_535 *); 

int main()
{
    Queue_535 q1 = {-1, -1};
    int choice_535;
    do
    {
        printf("1. Insertion\n2. Display\n3. Deletion\n4. Exit\n->: ");
        scanf("%d", &choice_535);
        int val_535;
        printf("\n");
        switch (choice_535)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val_535);
            enqueue_535(&q1, val_535);
            show_queue_535(&q1);
            break;
        case 2:
            show_queue_535(&q1);
            break;
        case 3:
            printf("Deleted element: ");
            printf("%d\n", dequeue_535(&q1));
            show_queue_535(&q1);
            break;
        default:
            printf("Exiting...\n");
        }
        printf("----------------------------------\n");
    } while (choice_535 >= 1 && choice_535 <= 3);
    return 0;
}

void enqueue_535(Queue_535 *que_535, int num)
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
    que_535->data_535[que_535->rear_535] = num;
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

void show_queue_535(Queue_535 *que_535)
{
    Queue_535 tempQue_535 = {-1, -1};
    while (!isEmpty_535(que_535))
    {
        enqueue_535(&tempQue_535, que_535->data_535[que_535->front_535]);
        printf("%d->", dequeue_535(que_535));
    }
    while (!isEmpty_535(&tempQue_535))
    {
        enqueue_535(que_535, dequeue_535(&tempQue_535));
    }
    printf("\b\b \n");
}

