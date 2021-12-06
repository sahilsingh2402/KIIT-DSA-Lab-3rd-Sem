#include <stdio.h>
#include <stdlib.h>

#define DEFNULL_535 -1
#define MAXSIZE_535 10

static int maxpriority_535 = -1;

typedef struct Queue_535
{
    int front_535[MAXSIZE_535];
    int rear_535[MAXSIZE_535];
    int data_535[MAXSIZE_535][MAXSIZE_535];
} Queue_535;

Queue_535 *create_535();
void enqueue_535(Queue_535 **, int, int);
int dequeue_535(Queue_535 **);
int peek_535(Queue_535 *);
int isFull_535(Queue_535 *, int);
int isEmpty_535(Queue_535 *, int);
void show_queue_535(Queue_535 *);

int main()
{
    Queue_535 *q1 = create_535();
    int choice_535;
    do
    {
        printf("1) Insertion\n2) Display\n3) Deletion\n4) Exit\n->: ");
        scanf("%d", &choice_535);
        int val;
        printf("\n");
        switch (choice_535)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            printf("Enter priority: ");
            int pri;
            scanf("%d", &pri);
            enqueue_535(&q1, val, pri);
            show_queue_535(q1);
            break;
        case 2:
            show_queue_535(q1);
            break;
        case 3:
            printf("Deleted element: ");
            printf("%d\n", dequeue_535(&q1));
            show_queue_535(q1);
            break;
        default:
            printf("Exiting...\n");
        }
        printf("----------------------------------\n");
    } while (choice_535 >= 1 && choice_535 <= 3);
    return 0;
}

Queue_535 *create_535()
{
    Queue_535 *queue_535 = (Queue_535 *)malloc(sizeof(Queue_535));
    for (int i = 0; i < MAXSIZE_535; i++)
    {
        queue_535->front_535[i] = queue_535->rear_535[i] = -1;
    }
    return queue_535;
}

void enqueue_535(Queue_535 **que_535, int num_535, int priority_535)
{
    if (priority_535 > MAXSIZE_535 || priority_535 < 0)
    {
        printf("Invalid Priority\n");
        return;
    }
    if (isFull_535(*que_535, priority_535))
    {
        printf("Overflow!\n");
        return;
    }
    else if (isEmpty_535(*que_535, priority_535))
        (*que_535)->front_535[priority_535] = (*que_535)->rear_535[priority_535] = 0;
    else
        (*que_535)->rear_535[priority_535] =
            ((*que_535)->rear_535[priority_535] + 1) % MAXSIZE_535;
    if (priority_535 > maxpriority_535)
        maxpriority_535 = priority_535;
    (*que_535)->data_535[priority_535][(*que_535)->rear_535[priority_535]] = num_535;
}

int dequeue_535(Queue_535 **que_535)
{
    for (int i = maxpriority_535; i >= 0; i--)
    {
        int retIndex = (*que_535)->front_535[i];
        if (!isEmpty_535(*que_535, i) && (*que_535)->front_535[i] ==
                                             (*que_535)->rear_535[i])
        {
            (*que_535)->front_535[i] = (*que_535)->rear_535[i] = -1;
            return (*que_535)->data_535[i][retIndex];
        }
        else if (!isEmpty_535(*que_535, i))
        {
            (*que_535)->front_535[i] =
                ((*que_535)->front_535[i] + 1) % MAXSIZE_535;
            return (*que_535)->data_535[i][retIndex];
        }
    }
    return DEFNULL_535;
}

int peek_535(Queue_535 *que_535)
{
    for (int i = maxpriority_535; i >= 0; i++)
    {
        if (!isEmpty_535(que_535, i))
            return que_535->data_535[i][que_535->front_535[i]];
    }
    return DEFNULL_535;
}

int isFull_535(Queue_535 *que_535, int priority_535)
{
    if ((que_535->rear_535[priority_535] + 1) % MAXSIZE_535 ==
        que_535->front_535[priority_535])
        return 1;
    return 0;
}

int isEmpty_535(Queue_535 *que_535, int priority_535)
{
    if (que_535->front_535[priority_535] == -1)
        return 1;
    return 0;
}

void show_queue_535(Queue_535 *que_535)
{
    for (int i = maxpriority_535; i >= 0; i--)
    {
        int start_535 = que_535->front_535[i];
        while (start_535 != que_535->rear_535[i])
        {
            printf("%d->", que_535->data_535[i][start_535]);
            start_535 = (start_535 + 1) % MAXSIZE_535;
        }
        if (!isEmpty_535(que_535, i))
            printf("%d->", que_535->data_535[i][start_535]);
    }
    printf("\b\b \n");
}

