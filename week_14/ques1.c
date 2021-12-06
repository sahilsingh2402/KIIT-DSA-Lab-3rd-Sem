#include <stdio.h>
#include <stdlib.h>
#define NULLpt -999
typedef int Node;
typedef struct Stack
{
    Node data;
    struct Stack *link;
} Stack;
typedef struct QueNode
{
    int data;
    struct QueNode *link;
} QueNode;
typedef struct Queue
{
    QueNode *front;
    QueNode *rear;
} Queue;
typedef struct Graph
{
    int **adjMatrix;
    int len;
} Graph;
int isEmpty(Queue *);
void enqueue(Queue *, int);
int dequeue(Queue *);
int peek(Queue *);
int isEmpty_stack(Stack *);
void push(Stack **, int);
int pop(Stack **);
int top(Stack *);
void initialise(Graph *, int);
void create_graph(Graph *);
void DFS(Graph *, int);
void BFS(Graph *, int);
void display(Graph *);
int main()
{
    int len;
    printf("Enter the total number of nodes: ");
    scanf("%d", &len);
    Graph graph;
    initialise(&graph, len);
    int choice, start;
    do
    {
        printf("\n------GRAPH OPERATIONS------\n");
        printf("1) Create Graph\n");
        printf("2) Depth First Traversal from a node\n");
        printf("3) Breadth First Traversal from a node\n");
        printf("4) Display Graph\n");
        printf("5) Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            create_graph(&graph);
            break;
        case 2:
            printf("Enter starting node: ");
            scanf("%d", &start);
            DFS(&graph, start);
            break;
        case 3:
            printf("Enter starting node: ");
            scanf("%d", &start);
            BFS(&graph, start);
            break;
        case 4:
            display(&graph);
            break;
        default:
            printf("Exiting...\n");
        }
        printf("--------------------------------\n");
    } while (choice >= 1 && choice <= 4);
    return 0;
}
void initialise(Graph *graph, int len)
{
    graph->len = len;
    graph->adjMatrix = (int **)calloc(len, sizeof(int *));
    for (int i = 0; i < len; i++)
        graph->adjMatrix[i] = (int *)calloc(len,
                                            sizeof(int));
}
void create_graph(Graph *graph)
{
    printf("--:Enter the nodes connected by adjMatrix edge:-- \n\n");
    char ch;
    int i, j;
    do
    {
        do
        {
            printf("Node from which the edge originates: ");
            scanf("%d", &i);
            if (i >= graph->len)
                printf("Invalid index entered!\n\n");
        } while (i >= graph->len);
        do
        {
            printf("Node at which the edge terminates: ");
            scanf("%d", &j);
            if (j >= graph->len)
                printf("Invalid index entered!\n\n");
        } while (j >= graph->len);
        graph->adjMatrix[i][j] = 1;
        printf("\nEnter \'Y\' to further create graph: ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}
void DFS(Graph *graph, int start)
{
    if (start >= graph->len)
    {
        printf("Invalid Location!\n");
        return;
    }
    int *visited = (int *)calloc(graph->len, sizeof(int));
    int i;
    printf("%d->", start);
    visited[start] = 1;
    Stack *stack = NULL;
    push(&stack, start);
    while (!isEmpty_stack(stack))
    {
        start = top(stack);
        for (i = 0; i < graph->len; i++)
        {
            if (graph->adjMatrix[start][i] == 1 && visited[i] == 0)
            {
                push(&stack, i);
                printf("%d->", i);
                visited[i] = 1;
                break;
            }
        }
        if (i == graph->len)
            pop(&stack);
    }
    free(visited);
    printf("\b\b \n");
}
void BFS(Graph *graph, int start)
{
    if (start >= graph->len)
    {
        printf("Invalid Location!\n");
        return;
    }
    int *visited = (int *)calloc(graph->len, sizeof(int));
    Queue queue = {NULL, NULL};
    enqueue(&queue, start);
    visited[start] = 1;
    while (!isEmpty(&queue))
    {
        start = dequeue(&queue);
        printf("%d->", start);
        for (int i = 0; i < graph->len; i++)
        {
            if (graph->adjMatrix[start][i] == 1 && visited[i] == 0)
            {
                enqueue(&queue, i);
                visited[i] = 1;
            }
        }
    }
    free(visited);
    printf("\b\b \n");
}
void display(Graph *graph)
{
    printf(" ");
    for (int i = 0; i < graph->len; i++)
        printf("%d ", i);
    printf("\n ");
    for (int i = 0; i < graph->len; i++)
        printf("- ");
    printf("\n");
    for (int i = 0; i < graph->len; i++)
    {
        printf("%d | ", i);
        for (int j = 0; j < graph->len; j++)
        {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}
int isEmpty(Queue *que)
{
    if (que->front == NULL)
        return 1;
    return 0;
}
void enqueue(Queue *que, int data)
{
    QueNode *temp = (QueNode *)malloc(sizeof(QueNode));
    temp->data = data;
    temp->link = NULL;

    if (isEmpty(que))
    {
        que->front = que->rear = temp;
        return;
    }

    que->rear->link = temp;
    que->rear = que->rear->link;
}
int dequeue(Queue *que)
{
    if (isEmpty(que))
        return NULLpt;

    QueNode *temp = que->front;
    que->front = que->front->link;

    if (que->front == NULL)
        que->rear = NULL;

    int n = temp->data;
    free(temp);
    return n;
}
int peek(Queue *que)
{
    if (isEmpty(que))
        return NULLpt;
    return que->front->data;
}
int isEmpty_stack(Stack *stack)
{
    if (!stack)
        return 1;
    return 0;
}
void push(Stack **stack, int data)
{
    Stack *temp = (Stack *)malloc(sizeof(Stack));
    temp->data = data;
    temp->link = *stack;
    *stack = temp;
}
int pop(Stack **stack)
{
    if (isEmpty_stack(*stack))
    {
        printf("\nUnderflow!");
        return -999;
    }

    Stack *temp = (*stack);
    *stack = (*stack)->link;

    int val = temp->data;
    free(temp);
    return val;
}
int top(Stack *stack)
{
    return stack->data;
}
